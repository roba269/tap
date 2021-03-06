/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/
/*
   +------------------------------------------+
   | Type Analyzer for PHP                    |
   | Modified work Copyright 2017 Houzz, Inc  |
   +------------------------------------------+
*/

#pragma once

#include <glog/logging.h>
#include <cassert>
#include "ast_decls.h"
#include "visitor/ast_visitor.h"
#include "parser/location.h"

namespace Tap {

class AstNode {
  public:
    AstNode(const HPHP::Location::Range& range) : range{range} {}
    virtual ~AstNode() {}
    virtual void accept(AstVisitor& v) = 0;
    
    virtual VisitorReturnType simpleAccept(AstVisitor& v) {
      LOG(FATAL) << "shouldn't come here";
    }
    
    const HPHP::Location::Range& getRange() const {return range;}
    
  private:
    HPHP::Location::Range range;
};

}
