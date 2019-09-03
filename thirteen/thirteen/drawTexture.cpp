#include <d3d9.h>
#include <d3dx9.h>
#include <D3dx9tex.h>

#include"DrawTexture.h"
#include"Engine.h"

const int D3DFVF_CUSTOMVERTEX(D3DFVF_XYZRHW | D3DFVF_TEX1);//(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);

void Draw(float x, float y, float width, float height, float tu, float tv, float tu_width, float tv_height, LPDIRECT3DTEXTURE9* Texture, DirectX directX)
{

	CUSTOMVERTEX customvertex[4] = {
	{x        ,y         ,0,1,tu           ,tv            },
	{x + width,y         ,0,1,tu + tu_width,tv            },
	{x + width,y + height,0,1,tu + tu_width,tv + tv_height},
	{x        ,y + height,0,1,tu           ,tv + tv_height},
	};

	directX.pDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	directX.pDevice->SetTexture(0, *Texture);
	directX.pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, customvertex, sizeof(CUSTOMVERTEX));

}

void DrawTest(float x, float y, float width, float height, float tu, float tv, float tu_width, float tv_height, LPDIRECT3DTEXTURE9* Texture, DirectX directX)
{

	CUSTOMVERTEX customvertex[4] = {
	{x        ,y         ,0,1,tu      ,tv            },
	{x + width,y         ,0,1,tu_width,tv            },
	{x + width,y + height,0,1,tu_width,tv_height},
	{x        ,y + height,0,1,tu      ,tv_height},
	};

	directX.pDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	directX.pDevice->SetTexture(0, *Texture);
	directX.pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, customvertex, sizeof(CUSTOMVERTEX));

}

void DrawEx(float x, float y, float width, float height, LPDIRECT3DTEXTURE9* Texture, DirectX directX)
{

	CUSTOMVERTEX customvertex[4] = {
	{x        ,y         ,  0, 1.0f,0.0f, 0.0f},
	{x + width,y         ,  0, 1.0f,1.0f, 0.0f},
	{x + width,y + height,  0, 1.0f,1.0f, 1.0f},
	{x        ,y + height,  0, 1.0f,0.0f, 1.0f},
	};

	directX.pDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	directX.pDevice->SetTexture(0, *Texture);
	directX.pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, customvertex, sizeof(CUSTOMVERTEX));

}

void LoadTexture(const char* file_name, LPDIRECT3DTEXTURE9* Texture, int texture_number, DirectX* directX)
{
	HRESULT result = D3DXCreateTextureFromFile(directX->pDevice, file_name, Texture);

	if ((_D3DXERR)result == D3DXERR_INVALIDDATA)
	{
		OutputDebugString(TEXT("\nテクスチャファイルが見つかりません\n"));
	}
}

///////////////////////////////////////////////////////////////////////////////////////

#define MAP_SIZE_WIDTH (28)	
#define MAP_SIZE_HEIGHT (20)

void DrawMap(MapChipData MapData, DirectX* directX, LPDIRECT3DTEXTURE9* Texture)
{
	float cy = MapData.m_chip_y / MapData.m_texture_height;// 高さ
	float cx = MapData.m_chip_x / MapData.m_texture_width; // 横
	float cx_size = MapData.m_mapChip_widht / MapData.m_texture_width;
	float cy_size = MapData.m_mapChip_height / MapData.m_texture_height;

	float cu_add = cx + cx_size;
	float cv_add = cy + cy_size;

	CUSTOMVERTEX sprite[] =
	{
		{ MapData.m_draw_x                          , MapData.m_draw_y                           , 0.0f, 1.0f,cx      ,cy      },
		{ MapData.m_draw_x + MapData.m_mapChip_widht, MapData.m_draw_y                           , 0.0f, 1.0f,cu_add  ,cy      },
		{ MapData.m_draw_x + MapData.m_mapChip_widht, MapData.m_draw_y + MapData.m_mapChip_height, 0.0f, 1.0f,cu_add  ,cv_add  },
		{ MapData.m_draw_x                          , MapData.m_draw_y + MapData.m_mapChip_height, 0.0f, 1.0f,cx      ,cv_add  },
	};

	directX->pDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
	directX->pDevice->SetTexture(0, *Texture);
	directX->pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, sprite, sizeof(CUSTOMVERTEX));
}

void DrawMapChip(DirectX* directX, MapChipData MapData, LPDIRECT3DTEXTURE9* Texture, int MapChipList[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH])
{
	for (int i = 0; i < MapData.m_map_height_number; i++)
	{
		for (int j = 0; j < MapData.m_map_widht_number; j++)
		{
			int chip_id = MapChipList[i][j];

			int width_num = MapData.m_texture_width / MapData.m_mapChip_widht;
			int height_num = MapData.m_texture_height / MapData.m_mapChip_height;

			float chip_pos_x = (float)((chip_id % width_num) * MapData.m_mapChip_widht);
			float chip_pos_y = (float)((chip_id / height_num) * MapData.m_mapChip_height);

			// 描画する場所の指定 // 
			MapData.m_chip_x = chip_pos_x;
			MapData.m_chip_y = chip_pos_y;
			// チップ指定 //
			MapData.m_draw_x = MapData.m_mapChip_widht * j + 80;
			MapData.m_draw_y = MapData.m_mapChip_height * i + 80;

			DrawMap(MapData, directX, Texture);

		}

	}

}
