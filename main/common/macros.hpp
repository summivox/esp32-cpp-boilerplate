#pragma once

#include "esp_err.h"
#include "esp_log.h"

#if CONFIG_ESP_SYSTEM_PANIC_PRINT_HALT
#define DIEDIEDIE abort()
#else
#warning "Consider changing system panic behavior to CONFIG_ESP_SYSTEM_PANIC_PRINT_HALT."
#define DIEDIEDIE while (1)
#endif

/// If `expr` evaluates to an error code other than `ESP_OK`, print log and return `ret`.
#define OK_OR_RETURN(expr, ret)                                                                  \
  do {                                                                                           \
    if (const esp_err_t err = (expr); unlikely(err != ESP_OK)) {                                 \
      ESP_LOGE("", "%s:%d TRY(%s) fail => %s", __FILE__, __LINE__, #expr, esp_err_to_name(err)); \
      return ret;                                                                                \
    }                                                                                            \
  } while (0)

/// If `expr` evalutes to an error code other than `ESP_OK`, print log and return this error code.
#define TRY(expr) OK_OR_RETURN(expr, err)

/// If `expr` evaluates to falsey, print log and abort.
#define CHECK(expr)                                                    \
  do {                                                                 \
    if (unlikely(!(expr))) {                                           \
      ESP_LOGE("", "%s:%d CHECK(%s) fail", __FILE__, __LINE__, #expr); \
      DIEDIEDIE;                                                       \
    }                                                                  \
  } while (0)

/// If `expr` evaluates to an error code other than `ESP_OK`, print log and abort.
#define CHECK_OK(expr)                     \
  do {                                     \
    const esp_err_t result = (expr);       \
    if (unlikely(result != ESP_OK)) {      \
      ESP_LOGE(                            \
          "",                              \
          "%s:%d CHECK_OK(%s) fail => %s", \
          __FILE__,                        \
          __LINE__,                        \
          #expr,                           \
          esp_err_to_name(result));        \
      DIEDIEDIE;                           \
    }                                      \
  } while (0)

/// If `expr` evaluates to `nullptr`, print log and abort; otherwise returns the evaluated value.
/// Useful in the member initialization list in a class constructor.
/// \returns evaluated value of `expr`
#define CHECK_NOTNULL(expr)                                                    \
  ({                                                                           \
    auto&& xx = (expr);                                                        \
    if (unlikely(xx == nullptr)) {                                             \
      ESP_LOGE("", "%s:%d CHECK_NOTNULL(%s) fail", __FILE__, __LINE__, #expr); \
      DIEDIEDIE;                                                               \
    }                                                                          \
    xx;                                                                        \
  })

/// Place this macro inside a class to prevent instances of the class from being copied or moved.
#define NON_COPYABLE_NOR_MOVABLE(T)    \
  T(T const&) = delete;                \
  void operator=(T const& t) = delete; \
  T(T&&) = delete;
