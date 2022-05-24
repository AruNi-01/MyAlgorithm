/*
 * @Descripttion: 棋盘覆盖问题
 * @Author: AruNi
 * @Date: 2022-04-19 13:27:07
 */
#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;

int tile = 0;       // 记录L型骨牌的数量
int Board[100][100];

/* 
参数:
    tr:棋盘左上角方格的行号
    tc:棋盘左上角方格的列号
    dr:特殊方格所在的行号 
    dc:特殊方格所在的列号
    size:棋盘的长度 
*/
void ChessBoard(int tr, int tc, int dr, int dc, int size) {
    if(size == 1) return;
	
    int t = ++tile;  // L型骨牌号 
    int s = size / 2;  // 分割棋盘

    // 覆盖左上角子棋盘	
    if(dr < tr + s && dc < tc + s)  // 特殊方格在此棋盘中
    	ChessBoard(tr, tc, dr, dc, s);   
    else {  // 此棋盘中无特殊方格		
    	Board[tr + s - 1][tc + s - 1] = t;  // 用 t号 L型骨牌覆盖右下角 
    	ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);  // 覆盖其余方格	
    } 

    // 覆盖右上角子棋盘 
    if(dr < tr + s && dc >= tc + s)
    	ChessBoard(tr, tc + s, dr, dc, s);  // 特殊方格在此棋盘中 
    else {  // 此棋盘中无特殊方格 
    	Board[tr + s - 1][tc + s] = t;  // 用 t号 L型骨牌覆盖左下角 
    	ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);  // 覆盖其余方格	
    }

    // 覆盖左下角子棋盘
    if(dr >= tr + s && dc < tc + s)
    	ChessBoard(tr + s, tc, dr, dc, s);
    else {
    	Board[tr + s][tc + s - 1] = t;
    	ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);  // 覆盖其余方格	
    }

    // 覆盖右下角子棋盘
    if(dr >= tr + s && dc >= tc + s)
    	ChessBoard(tr + s, tc + s, dr, dc, s);
    else {
    	Board[tr + s][tc + s] = t;
    	ChessBoard(tr + s, tc + s, tr + s, tc + s, s);
    } 
}

int main() {
    int k, x, y, size;
    cin >> k >> x >> y;
    size = (int)pow(2, k);
  	
    ChessBoard(1, 1, x, y, size);
	
    for(int i = 1; i <= size; i ++ )
    {
        for(int j = 1; j <= size; j ++ )
            cout << Board[i][j] << " ";
        puts("");
    }

	system("pause");
    return 0;
} 