#ifndef DRAWTEXTURE
#define DRAWTEXTURE

#include"Engine.h"

class MapChipData
{
public:
	int   m_map_height_number =  20; // マップチップの横の個数
	int   m_map_widht_number  =  28; // マップチップの縦の個数
	float m_mapChip_height    =  40; // マップチップの一つの幅
	float m_mapChip_widht     =  40; // マップチップの一つの高さ
	float m_texture_height    = 256; // マップチップの画像の幅
	float m_texture_width     = 256; // マップチップの画像の高さ
	float m_draw_x;                  // 描画位置(X座標)
	float m_draw_y;                  // 描画位置(Y座標)
	float m_chip_x;                  // 統合画像から切り取る座標(X座標)
	float m_chip_y;                  // 統合画像から切り取る座標(Y座標)
};

const int TEXTUREMAX(20); // 各シーンで読み込みができる画像の最大枚数

// テクスチャデータ						
struct TEXTUREDATA  
{

	LPDIRECT3DTEXTURE9 m_pTexture[TEXTUREMAX];  // テクスチャ情報
	float m_width;					// テクスチャの幅
	float m_height;					// テクスチャの高さ

};

// マップチップでの画像数
enum MAPCHIP_TEXTURE_ID
{
	Non = -1,		// 無し
	MapChip,		// マップチップ	
	MaxTextureId	// 最大数
};

typedef struct
{
	float	// 頂点座標
		x,  // 幅
		y,  // 高さ
		z;  // 奥行

	float   // 除算数
		rhw;

	float   // テクスチャ座標
		tu,  // 幅
		tv;	// 高さ
} CUSTOMVERTEX, * P_CUSTOMVERTEX;

#define MAP_SIZE_WIDTH (28)	
#define MAP_SIZE_HEIGHT (20)

void Draw(float x, float y, float width, float height, float tu, float tv, float tu_width, float tv_height, LPDIRECT3DTEXTURE9* Texture, DirectX directX);

void DrawEx(float x, float y, float width, float height, LPDIRECT3DTEXTURE9* Texture, DirectX directX);

void LoadTexture(const char* file_name, LPDIRECT3DTEXTURE9* Texture, int texture_number, DirectX* directX);

void DrawMapChip(DirectX* directX, MapChipData MapData, LPDIRECT3DTEXTURE9* Texture, int MapChipList[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH]);

void DrawMap(MapChipData MapData, DirectX* directX, LPDIRECT3DTEXTURE9* Texture);

void DrawTest(float x, float y, float width, float height, float tu, float tv, float tu_width, float tv_height, LPDIRECT3DTEXTURE9* Texture, DirectX directX);

#endif // !1