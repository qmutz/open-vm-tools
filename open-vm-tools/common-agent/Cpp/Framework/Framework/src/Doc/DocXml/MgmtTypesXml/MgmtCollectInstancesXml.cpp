/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (C) 2012-2016 VMware, Inc.  All rights reserved. -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"

#include "Doc/DocXml/CafCoreTypesXml/ClassSpecifierXml.h"
#include "Doc/DocXml/CafCoreTypesXml/ParameterCollectionXml.h"

#include "Doc/CafCoreTypesDoc/CClassSpecifierDoc.h"
#include "Doc/CafCoreTypesDoc/CParameterCollectionDoc.h"
#include "Doc/MgmtTypesDoc/CMgmtCollectInstancesDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/MgmtTypesXml/MgmtCollectInstancesXml.h"

using namespace Caf;

void MgmtCollectInstancesXml::add(
	const SmartPtrCMgmtCollectInstancesDoc mgmtCollectInstancesDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("MgmtCollectInstancesXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(mgmtCollectInstancesDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string jobIdVal =
			BasePlatform::UuidToString(mgmtCollectInstancesDoc->getJobId());
		CAF_CM_VALIDATE_STRING(jobIdVal);
		thisXml->addAttribute("jobId", jobIdVal);

		const SmartPtrCClassSpecifierDoc classSpecifierVal =
			mgmtCollectInstancesDoc->getClassSpecifier();
		CAF_CM_VALIDATE_SMARTPTR(classSpecifierVal);

		const SmartPtrCXmlElement classSpecifierXml =
			thisXml->createAndAddElement("classSpecifier");
		ClassSpecifierXml::add(classSpecifierVal, classSpecifierXml);

		const SmartPtrCParameterCollectionDoc parameterCollectionVal =
			mgmtCollectInstancesDoc->getParameterCollection();
		if (! parameterCollectionVal.IsNull()) {
			const SmartPtrCXmlElement parameterCollectionXml =
				thisXml->createAndAddElement("parameterCollection");
			ParameterCollectionXml::add(parameterCollectionVal, parameterCollectionXml);
		}
	}
	CAF_CM_EXIT;
}

SmartPtrCMgmtCollectInstancesDoc MgmtCollectInstancesXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("MgmtCollectInstancesXml", "parse");

	SmartPtrCMgmtCollectInstancesDoc mgmtCollectInstancesDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string jobIdStrVal =
			thisXml->findRequiredAttribute("jobId");
		UUID jobIdVal = CAFCOMMON_GUID_NULL;
		if (! jobIdStrVal.empty()) {
			BasePlatform::UuidFromString(jobIdStrVal.c_str(), jobIdVal);
		}

		const SmartPtrCXmlElement classSpecifierXml =
			thisXml->findRequiredChild("classSpecifier");

		SmartPtrCClassSpecifierDoc classSpecifierVal;
		if (! classSpecifierXml.IsNull()) {
			classSpecifierVal = ClassSpecifierXml::parse(classSpecifierXml);
		}

		const SmartPtrCXmlElement parameterCollectionXml =
			thisXml->findOptionalChild("parameterCollection");

		SmartPtrCParameterCollectionDoc parameterCollectionVal;
		if (! parameterCollectionXml.IsNull()) {
			parameterCollectionVal = ParameterCollectionXml::parse(parameterCollectionXml);
		}

		mgmtCollectInstancesDoc.CreateInstance();
		mgmtCollectInstancesDoc->initialize(
			jobIdVal,
			classSpecifierVal,
			parameterCollectionVal);
	}
	CAF_CM_EXIT;

	return mgmtCollectInstancesDoc;
}

