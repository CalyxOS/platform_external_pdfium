// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_datamodel.h"

namespace {

constexpr wchar_t kName[] = L"dataModel";

}  // namespace

CXFA_DataModel::CXFA_DataModel(CXFA_Document* doc, XFA_XDPPACKET packet)
    : CXFA_Node(doc,
                packet,
                XFA_XDPPACKET_Datasets,
                XFA_ObjectType::ModelNode,
                XFA_Element::DataModel,
                nullptr,
                nullptr,
                kName) {}

CXFA_DataModel::~CXFA_DataModel() {}
