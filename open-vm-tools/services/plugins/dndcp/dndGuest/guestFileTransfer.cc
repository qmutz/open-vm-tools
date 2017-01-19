/*********************************************************
 * Copyright (C) 2010-2017 VMware, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation version 2.1 and no later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the Lesser GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA.
 *
 *********************************************************/

/**
 * @guestFileTransfer.cc --
 *
 * Implementation of common layer file transfer object for guest.
 */

#include "guestFileTransfer.hh"
#include "fileTransferRpcV4.hh"

extern "C" {
   #include "debug.h"
   #include "hgfsServer.h"
}


/**
 * Create transport object and register callback.
 *
 * @param[in] transport pointer to a transport object.
 */

GuestFileTransfer::GuestFileTransfer(DnDCPTransport *transport)
{
   ASSERT(transport);
   mRpc = new FileTransferRpcV4(transport);
   mRpc->Init();
   mRpc->HgfsPacketReceived.connect(
      sigc::mem_fun(this, &GuestFileTransfer::OnRpcRecvHgfsPacket));
   HgfsServerManager_DataInit(&mHgfsServerMgrData,
                              "DnDGuestHgfsMgr",
                              NULL,
                              NULL);
   HgfsServerManager_Register(&mHgfsServerMgrData);
}


/**
 * Destructor.
 */
GuestFileTransfer::~GuestFileTransfer(void)
{
   delete mRpc;
   mRpc = NULL;
   HgfsServerManager_Unregister(&mHgfsServerMgrData);
}


/**
 * Callback after received message.
 *
 * @param[in] sessionId dnd session id.
 * @param[in] packet hgfs packet from the peer.
 * @param[in] packetSize hgfs pack size.
 */

void
GuestFileTransfer::OnRpcRecvHgfsPacket(uint32 sessionId,
                                       const uint8 *packet,
                                       size_t packetSize)
{
   char replyPacket[HGFS_LARGE_PACKET_MAX];
   size_t replyPacketSize;

   ASSERT(packet);
   ASSERT(mRpc);

   /* Call hgfs server to process the request, and send reply back to peer. */
   HgfsServerManager_ProcessPacket(&mHgfsServerMgrData,
                                   (const char *)packet,
                                   packetSize,
                                   replyPacket,
                                   &replyPacketSize);
   mRpc->SendHgfsReply(sessionId, (const uint8 *)replyPacket, replyPacketSize);
}

