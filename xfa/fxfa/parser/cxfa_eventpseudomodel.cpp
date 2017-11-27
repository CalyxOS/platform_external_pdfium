// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_eventpseudomodel.h"

namespace {

constexpr wchar_t kName[] = L"eventPseudoModel";

}  // namespace

CXFA_EventPseudoModel::CXFA_EventPseudoModel(CXFA_Document* doc,
                                             XFA_XDPPACKET packet)
    : CXFA_Node(doc,
                packet,
                XFA_XDPPACKET_XDP,
                XFA_ObjectType::Object,
                XFA_Element::EventPseudoModel,
                nullptr,
                nullptr,
                kName) {}

CXFA_EventPseudoModel::~CXFA_EventPseudoModel() {}
