#ifndef TOML_VALUES
#define TOML_VALUES
#include "definitions.hpp"
#include <vector>
#include <string>
#include <memory>
#include <map>

namespace toml
{

template<typename T>
struct typed_value : public value_base
{
    T value;
    typed_value(){}
    ~typed_value() TOML_NOEXCEPT TOML_OVERRIDE {}
};

struct array_type : public value_base
{
    std::vector<toml::shared_ptr<value_base> > value;
    ~array_type() TOML_NOEXCEPT TOML_OVERRIDE {}
};

struct table_type : public value_base
{
    std::map<std::string, toml::shared_ptr<value_base> > value;
    ~table_type() TOML_NOEXCEPT TOML_OVERRIDE {}
};

}//toml

#endif /* TOML_VALUES */
