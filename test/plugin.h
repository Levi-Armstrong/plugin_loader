/*
 * Software License Agreement (Apache License)
 *
 * Copyright (c) 2022, Southwest Research Institute
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <memory>
#include <string>

namespace plugin_loader
{
/**
 * @brief Plugin interface implementation for testing
 */
class Printer
{
public:
  using Ptr = std::shared_ptr<Printer>;
  virtual void operator()() const = 0;

protected:
  friend class PluginLoader;
  static const std::string section;
};

/**
 * @brief Plugin interface implementation for testing
 */
class Shape
{
public:
  using Ptr = std::shared_ptr<Shape>;
  virtual void operator()() const = 0;

protected:
  friend class PluginLoader;
  static const std::string section;
};

struct ConsolePrinter : public Printer
{
public:
  void operator()() const override;
};

struct HelloWorldPrinter : public Printer
{
public:
  void operator()() const override;
};

struct Square : public Shape
{
public:
  void operator()() const override;
};

struct Triangle : public Shape
{
public:
  void operator()() const override;
};
}  // namespace plugin_loader

#include <plugin_loader/macros.h>
// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
#define EXPORT_PRINTER_PLUGIN(DERIVED_CLASS, ALIAS) EXPORT_CLASS_SECTIONED(DERIVED_CLASS, ALIAS, printer)
// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables)
#define EXPORT_SHAPE_PLUGIN(DERIVED_CLASS, ALIAS) EXPORT_CLASS_SECTIONED(DERIVED_CLASS, ALIAS, shape)
