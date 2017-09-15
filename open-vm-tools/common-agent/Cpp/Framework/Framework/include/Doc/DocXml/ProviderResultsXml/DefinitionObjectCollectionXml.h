/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (c) 2012 Vmware, Inc.  All rights reserved.
 *  -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#ifndef DefinitionObjectCollectionXml_h_
#define DefinitionObjectCollectionXml_h_


#include "Doc/ProviderResultsDoc/CDefinitionObjectCollectionDoc.h"

#include "Doc/DocXml/ProviderResultsXml/ProviderResultsXmlLink.h"
#include "Xml/XmlUtils/CXmlElement.h"

namespace Caf {

	/// Streams the DefinitionObjectCollection class to/from XML
	namespace DefinitionObjectCollectionXml {

		/// Adds the DefinitionObjectCollectionDoc into the XML.
		void PROVIDERRESULTSXML_LINKAGE add(
			const SmartPtrCDefinitionObjectCollectionDoc definitionObjectCollectionDoc,
			const SmartPtrCXmlElement thisXml);

		/// Parses the DefinitionObjectCollectionDoc from the XML.
		SmartPtrCDefinitionObjectCollectionDoc PROVIDERRESULTSXML_LINKAGE parse(
			const SmartPtrCXmlElement thisXml);
	}
}

#endif