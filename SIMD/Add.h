#pragma once

#include <iostream>

/* 
* @brief 16bit整数配列どうしの加算をC言語の加算命令で実行する
*/
void AddC(uint16_t a[], uint16_t b[], uint16_t c[], size_t size);

/* @brief 16bit整数配列どうしの加算をイントリンシックで実行する */
void AddWithM256i(uint16_t a[], uint16_t b[], uint16_t c[], size_t size);