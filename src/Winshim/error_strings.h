#pragma once
#pragma once

#ifndef ERROR_STRINGS_H
#define ERROR_STRINGS_H

#include <Windows.h>
LPCWSTR get_win_error_symbol(HRESULT hr);
LPCWSTR get_ndstatus_symbol(HRESULT hr);
LPCWSTR get_error_symbol(HRESULT hr);
#endif