/*
Copyright 2017 Houzz, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#pragma once

#include "tap_type.h"

namespace Tap {

class VoidTapType : public Tap::TapType {
  private:
    VoidTapType() {}

  public:
    static VoidTapType* getInstance() {
      static VoidTapType instance;
      return &instance;
    }

    virtual bool canAccept(const TapType* t) const {
      return false;
    }
    virtual bool equals(const TapType* t) const {
      return this == t;
    }
    virtual const TapType* intersect(const TapType* t) const {
      return this;
    }
    virtual const TapType* substract(const TapType* t) const {
      return this;
    }
    virtual std::string toString() const {
      return "void";
    }
    virtual const TapType* unionType(const TapType* t) const {
      return this;
    }
};

}

