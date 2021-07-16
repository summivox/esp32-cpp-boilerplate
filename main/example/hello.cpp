// Authors: summivox@gmail.com

#include "example/hello.hpp"  // the header for this file is always included first

// 1st include group: C/C++ system headers
#include <cmath>
#include <cstdio>

// 2nd include group: libraries / frameworks / dependencies
#include "esp_spi_flash.h"
#include "esp_system.h"
#include "fmt/core.h"
#include "scope_guard/scope_guard.hpp"

// 3rd include group: headers from the same project
#include "common/macros.hpp"
#include "common/task.hpp"
#include "common/utils.hpp"

using fmt::print;

// this should be from `cmath`
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif  // M_PI

namespace example {

namespace {

// By convention, this is used as the 1st argument for ESP_LOGx macros to identify the log source.
constexpr char TAG[] = "example/hello";

// Functions and global variables local to this file can go here (no need to declare as `static`).

esp_err_t EspOkExample() {
  ESP_LOGI(TAG, "EspOkExample()");
  return ESP_OK;
}

esp_err_t EspErrorExample() {
  ESP_LOGI(TAG, "EspErrorExample()");
  return ESP_ERR_INVALID_STATE;
}

}  // namespace

class ExampleTask : public Task {
 public:
  virtual ~ExampleTask() = default;
  using Task::SpawnSame;

 protected:
  // entry point of this task (must not return)
  void Run() override {
    ESP_LOGI(TAG, "%s", __PRETTY_FUNCTION__);
    example::PrintChipInfo();
    CallMoreExamples();

    ESP_LOGW(TAG, "Entering busy loop...");
    TickType_t last_wake_time = xTaskGetTickCount();
    while (1) {
      ESP_LOGI(TAG, "still alive...");
      vTaskDelayUntil(&last_wake_time, pdMS_TO_TICKS(10000));
    }
  }

 private:
  esp_err_t CallMoreExamples() {
    FmtDeferExample();
    if (const esp_err_t err = TryMacroExample(); err != ESP_OK) {
      ESP_LOGI(TAG, "TryMacroExample returned: %s", esp_err_to_name(err));
    } else {
      ESP_LOGE(TAG, "should not happen!");
    }
    return ESP_OK;
  }
};

ExampleTask g_example_task;

void StartExampleTask() {
  g_example_task.SpawnSame(/*name*/ TAG, /*stack size*/ 4096, /*priority*/ 2);
}

void PrintChipInfo() {
  ESP_LOGI(TAG, "PrintChipInfo()");
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);
  print(
      "This is ESP32 chip with {} CPU cores, WiFi{}{}, ",
      chip_info.cores,
      (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
      (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

  print("silicon revision {}, ", chip_info.revision);

  print(
      "{}MB {} flash\n",
      spi_flash_get_chip_size() / (1024 * 1024),
      (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
}

void FmtDeferExample() {
  ESP_LOGI(TAG, "FmtDeferExample()");
  DEFER { print("--- this is a deferred statement ---\n"); };
  print("fmtlib does python-styled formatting and printing, like this: PI = {:+010.5f}\n", M_PI);

  if constexpr (1) {
    return;
  }

  ESP_LOGE(TAG, "unreachable (this line should not be printed)");
}

esp_err_t TryMacroExample() {
  ESP_LOGI(TAG, "TryMacroExample() --- expected TRY fail error below; see code");
  TRY(EspOkExample());     // <--- runs normally (no extra logging)
  TRY(EspErrorExample());  // <--- logs error and return after this call finishes
  TRY(EspOkExample());     // <--- not run because the previous TRY returns
  return ESP_OK;
}

}  // namespace example
