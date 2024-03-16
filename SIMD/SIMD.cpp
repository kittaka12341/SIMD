// SIMD.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <iomanip>

using namespace std;


void printClock(clock_t elapsedTime)
{
    cout << "elapsed time is " << elapsedTime << endl;
}

int main()
{
    clock_t start, end;

    /* C */
    const size_t size = 2000 * 2000;
    unsigned short a[size] = { 0 };
    unsigned short b[size] = { 0 };
    int c[size] = { 0 };
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

    cout << "a[0]=" << a[0] << "  a[size - 1]=" << a[size - 1] << endl;
    cout << "b[0]=" << b[0] << "  b[size - 1]=" << b[size - 1] << endl;
    cout << "c[0]=" << c[0] << "  c[size - 1]=" << c[size - 1] << endl;
    printClock(end - start);


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
