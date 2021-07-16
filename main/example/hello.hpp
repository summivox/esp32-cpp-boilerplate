// Authors: summivox@gmail.com

#pragma once

#include "esp_err.h"

namespace example {

/// Run all examples here in a task.
void StartExampleTask();

/// The default example included in ESP-IDF's own template app.
void PrintChipInfo();

/// Showcases fmtlib, an external dependency.
void FmtDeferExample();

/// Example for the handy `TRY` macro for handling ESP-IDF errors.
/// \returns an error code
esp_err_t TryMacroExample();

}  // namespace example
