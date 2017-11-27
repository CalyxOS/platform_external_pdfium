// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_logpseudomodel.h"

namespace {

constexpr wchar_t kName[] = L"logPseudoModel";

}  // namespace

CXFA_LogPseudoModel::CXFA_LogPseudoModel(CXFA_Document* doc,
                                         XFA_XDPPACKET packet)
    : CXFA_Node(doc,
                packet,
                XFA_XDPPACKET_XDP,
                XFA_ObjectType::Object,
                XFA_Element::LogPseudoModel,
                nullptr,
                nullptr,
                kName) {}

CXFA_LogPseudoModel::~CXFA_LogPseudoModel() {}
