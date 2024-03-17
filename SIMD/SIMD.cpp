// SIMD.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <iomanip>
#include <immintrin.h>

using namespace std;


void printClock(clock_t elapsedTime)
{
    cout << "elapsed time is " << elapsedTime << endl;
}

void printValue(uint16_t a[], uint16_t b[], uint16_t c[], size_t size)
{
    cout << "a[0]=" << a[0] << "  a[size - 1]=" << a[size - 1] << endl;
    cout << "b[0]=" << b[0] << "  b[size - 1]=" << b[size - 1] << endl;
    cout << "c[0]=" << c[0] << "  c[size - 1]=" << c[size - 1] << endl;
}

int main()
{
    clock_t start, end;

    /* C */
    const size_t size = 32 * 62 * 2000;
    __declspec(align(32)) uint16_t a[size] = { 0 };
    __declspec(align(32)) uint16_t b[size] = { 0 };
    __declspec(align(32)) uint16_t c[size] = { 0 };
    int i;

    for (i = 0; i < size; i++) {
        a[i] = 1;
        b[i] = 2;
    }

    start = clock();
    for (i = 0; i < size; i++) {
        c[i] = a[i] + b[i];
    }
    end = clock();

    printValue(a, b, c, size);
    printClock(end - start);

    /* 1度に256bitまとめて演算 (16bitを16要素分) */
    __declspec(align(32)) uint16_t c2[size] = { 0 };
    start = clock();
    const int units = sizeof(__m256) / sizeof(unsigned short);
    const int max = size / units;
    for (i = 0; i < max; i++) {
        /* C言語のデータ型からイントリンシックデータ型にコピー */
        __m256i ia = _mm256_load_si256((__m256i*)&a[i * units]);
        __m256i ib = _mm256_load_si256((__m256i*)&b[i * units]);

        /* 16bit整数加算 */
        __m256i y = _mm256_add_epi16(ia, ib);

        /* イントリンシックデータ型からC言語のデータ型にコピー */
        _mm256_store_si256((__m256i*)&c2[i * units], y);
    }
    end = clock();

    printValue(a, b, c2, size);
    printClock(end - start);

#if 0 /* PCがサポートしていないため実行不可 */
    /* 1度に512bitまとめて演算 (16bitを32要素分) */
    __declspec(align(32)) uint16_t c3[size] = { 0 };
    start = clock();
    const int units512 = sizeof(__m512) / sizeof(unsigned short);
    const int max512 = size / units512;
    for (i = 0; i < max512; i++) {
        /* C言語のデータ型からイントリンシックデータ型にコピー */
        __m512i ia = _mm512_load_si512((__m512i*) & a[i * units512]);
        __m512i ib = _mm512_load_si512((__m512i*) & b[i * units512]);

        /* 16bit整数加算 */
        __m512i y = _mm512_add_epi16(ia, ib);

        /* イントリンシックデータ型からC言語のデータ型にコピー */
        _mm512_store_si512((__m512i*) & c3[i * units512], y);
    }
    end = clock();

    printValue(a, b, c3, size);
    printClock(end - start);
#endif

}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
