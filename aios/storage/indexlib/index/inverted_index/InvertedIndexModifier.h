/*
 * Copyright 2014-present Alibaba Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include "autil/Log.h"
#include "autil/NoCopyable.h"
#include "indexlib/base/Status.h"
#include "indexlib/config/ITabletSchema.h"
#include "indexlib/document/normal/ModifiedTokens.h"

namespace indexlib::index {

class InvertedIndexModifier : public autil::NoCopyable
{
public:
    InvertedIndexModifier(const std::shared_ptr<indexlibv2::config::ITabletSchema>& schema) : _schema(schema) {}
    virtual ~InvertedIndexModifier() = default;
    virtual Status UpdateOneFieldTokens(docid_t docId, const document::ModifiedTokens& modifiedTokens,
                                        bool isForReplay) = 0;

protected:
    const std::shared_ptr<indexlibv2::config::ITabletSchema> _schema;
};
} // namespace indexlib::index
