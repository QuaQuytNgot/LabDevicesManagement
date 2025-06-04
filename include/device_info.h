// #ifndef DEVICE_INFO_H
// #define DEVICE_INFO_H

// #endif
#pragma once
#include <string>
#include <stddef.h>

/**
 * @struct device_info
 * @brief Structure representing device information
 * @details Contains name, date, ID 
 * of the device.
 */
struct device_info
{
    std::string name;
    std::string date;
    std::string ID;
    std::string category;
    double cost;
};

/**
 * @brief Standardize date 
 * @details Standardize date to format xx/xx/xxxx
 */
void date_standardize(device_info& x);
/**
 * @brief Standardize name 
 * @details Standardize name to format Abcdef Ghijk
 */
void name_standardize(device_info& x);
