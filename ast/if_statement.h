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

#include "statement.h"
#include "statement_list.h"

namespace HPHP {

class IfStatement : public Statement {
  public:
    IfStatement(const Location::Range& r, StatementListPtr stmts)
      : Statement(r), stmts{stmts} {}
      
    SIMPLE_VISIT_METHOD
    
    void accept(Tap::AstVisitor& v) override {
      stmts->accept(v);
      v.visit(this);
    }
    
    StatementListPtr getStmts() {return stmts;}
  private:
    StatementListPtr stmts;
};

}