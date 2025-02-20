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

#include "indexlib/base/FieldType.h"
#include "indexlib/index/common/hash_table/ClosedHashTableTraits.h"
#include "indexlib/index/common/hash_table/DenseHashTable.h"
#include "indexlib/index/common/hash_table/HashTableBase.h"
#include "indexlib/index/kv/FixedLenDenseHashTableCreator.h"

namespace indexlibv2::index {

template <typename KeyType, typename ValueType, bool useCompactBucket>
std::unique_ptr<HashTableAccessor>
FixedLenDenseHashTableCreator<KeyType, ValueType, useCompactBucket>::CreateHashTable() noexcept
{
    static constexpr bool HasSpecialKey = ClosedHashTableTraits<KeyType, ValueType, useCompactBucket>::HasSpecialKey;
    using HashTableType = DenseHashTable<KeyType, ValueType, HasSpecialKey, useCompactBucket>;
    return std::make_unique<HashTableType>();
}

} // namespace indexlibv2::index

#define INDEXLIB_KV_HASHTABLE_INSTANTIATION_VALUETYPE(ValueType)                                                       \
    template class indexlibv2::index::FixedLenDenseHashTableCreator<uint32_t, ValueType, true>;                        \
    template class indexlibv2::index::FixedLenDenseHashTableCreator<uint32_t, ValueType, false>;                       \
    template class indexlibv2::index::FixedLenDenseHashTableCreator<uint64_t, ValueType, true>;                        \
    template class indexlibv2::index::FixedLenDenseHashTableCreator<uint64_t, ValueType, false>;
