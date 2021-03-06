/**
 * Created by G-Canvas Open Source Team.
 * Copyright (c) 2017, Alibaba, Inc. All rights reserved.
 *
 * This source code is licensed under the Apache Licence 2.0.
 * For the full copyright and license information, please view
 * the LICENSE file in the root directory of this source tree.
 */
#ifndef __GCanvas__GCValue__
#define __GCanvas__GCValue__

#include <map>
#include <string>
#include <vector>

#define GC_SAFE_DELETE(p)                                                      \
    do                                                                         \
    {                                                                          \
        delete (p);                                                            \
        (p) = nullptr;                                                         \
    } while (0)

#define GC_BREAK_IF(cond)                                                      \
    if (cond) break

class Value;

typedef std::vector< Value > ValueVector;
typedef std::map< std::string, Value > ValueMap;
typedef std::map< int, Value > ValueMapIntKey;

class Value
{
public:
    Value(const Value &other);

    ~Value();

    Value &operator=(const Value &other);
    std::string asString() const;

    enum class Type
    {
        NONE = 0,
        BYTE,
        INTEGER,
        FLOAT,
        DOUBLE,
        BOOLEAN,
        STRING,
        VECTOR,
        MAP,
        INT_KEY_MAP
    };

private:
    void clear();
    void reset(Type type);

    union {
        unsigned char byteVal;
        int intVal;
        float floatVal;
        double doubleVal;
        bool boolVal;

        std::string *strVal;
        ValueVector *vectorVal;
        ValueMap *mapVal;
        ValueMapIntKey *intKeyMapVal;
    } mField;

    Type mType;
};

#endif
