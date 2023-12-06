// Copyright 2017 The PDFium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef XFA_FXFA_PARSER_CXFA_SCRIPT_H_
#define XFA_FXFA_PARSER_CXFA_SCRIPT_H_

#include "core/fxcrt/widestring.h"
#include "xfa/fxfa/parser/cxfa_node.h"

class CXFA_Script final : public CXFA_Node {
 public:
  enum class Type {
    Formcalc = 0,
    Javascript,
    Unknown,
  };

  static CXFA_Script* FromNode(CXFA_Node* pNode);

  CONSTRUCT_VIA_MAKE_GARBAGE_COLLECTED;
  ~CXFA_Script() override;

  Type GetContentType();
  XFA_AttributeValue GetRunAt();
  WideString GetExpression();

 private:
  CXFA_Script(CXFA_Document* doc, XFA_PacketType packet);
};

#endif  // XFA_FXFA_PARSER_CXFA_SCRIPT_H_
