#define _USE_MATH_DEFINES
#include <Novice.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#pragma region
#pragma endregion
const char kWindowTitle[] = "5002_元素パズル";
#pragma region 構造体
//構造体
typedef struct Vector2 {
	float x;
	float y;
}Vector2;

typedef struct Boss {
	Vector2 pos;
	float width;
	float height;
	float hp;
	float maxHp;
	float atk;
	int advantage;
	int weakness;
	int texture;
	int texture_hit;
}Boss;

typedef struct Player {
	Vector2 pos;
	float width;
	float height;
	float hp;
	float maxHp;
	float atk;
}Player;
#pragma endregion
#pragma region 関数
#pragma region 4x4
/// <summary>
/// 4x4の2次元配列を0にリセットする(4x4 矩阵 重置为0)
/// </summary>
/// <param name="arr">ターゲットの2次元配列</param>
void resetArr4x4to0(int arr[4][4]) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			arr[y][x] = 0;
		}
	}
}
/// <summary>
/// 4x4の2次元配列をリセットする(4x4 矩阵 重置)
/// </summary>
/// <param name="arr">ターゲットの2次元配列</param>
void resetArr4x4(int arr[4][4]) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			arr[y][x] = y + 1;
		}
	}
}

/// <summary>
/// 4x4の2次元配列の列を上方向に移動する。
/// </summary>
/// <param name="arr">ターゲットの2次元配列</param>
/// <param name="column">ターゲットの列</param>
void moveUp4x4(int arr[4][4], int column) {

	int temp = arr[0][column];  // 保存第一行的元素
	for (int i = 0; i < 3; i++) {
		arr[i][column] = arr[i + 1][column];  // 向上移动一位
	}
	arr[3][column] = temp;  // 将保存的元素移到最后一行

}

/// <summary>
/// 4x4の2次元配列の列を下方向に移動する。
/// </summary>
/// <param name="arr">ターゲットの2次元配列</param>
/// <param name="column">ターゲットの列</param>
void moveDown4x4(int arr[4][4], int column) {

	int temp = arr[3][column];  // 保存第一行的元素
	for (int i = 3; i >= 1; i--) {
		arr[i][column] = arr[i - 1][column];  // 向上移动一位
	}
	arr[0][column] = temp;  // 将保存的元素移到最后一行

}

/// <summary>
/// 4x4の2次元配列の行を左方向に移動する。
/// </summary>
/// <param name="array">ターゲットの2次元配列</param>
/// <param name="row">ターゲットの行</param>
void moveLeft4x4(int array[4][4], int row) {
	int temp = array[row][0]; // 保存第一行的第一个元素

	// 向左移动第一行的元素
	for (int i = 0; i < 3; i++) {
		array[row][i] = array[row][i + 1];
	}

	array[row][3] = temp; // 将保存的元素放到第一行的最后
}

/// <summary>
// /4x4の2次元配列の行を右方向に移動する。
/// </summary>
/// <param name="array">ターゲットの2次元配列</param>
/// <param name="row">ターゲットの行</param>
void moveRight4x4(int array[4][4], int row) {
	int temp = array[row][3]; // 保存第一行的最后一个元素

	// 向右移动第一行的元素
	for (int i = 3; i > 0; i--) {
		array[row][i] = array[row][i - 1];
	}

	array[row][0] = temp; // 将保存的元素放到第一行的第一个
}
#pragma endregion
#pragma region 5x5
/// <summary>
/// 5x5 の2次元配列を0にリセットする(5x5 矩阵 重置为0)
/// </summary>
/// <param name="arr">ターゲットの2次元配列</param>
void resetArr5x5to0(int arr[5][5]) {
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			arr[y][x] = 0;
		}
	}
}

/// <summary>
/// 5x5 の2次元配列をリセットする(4x4 矩阵 重置为0)
/// </summary>
/// <param name="arr">ターゲットの2次元配列</param>
void resetArr5x5(int arr[5][5]) {
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			arr[y][x] = y + 1;
		}
	}
}
/// <summary>
/// 5x5 の2次元配列の列を上方向に移動する。
/// </summary>
/// <param name="arr">ターゲットの2次元配列</param>
/// <param name="column">ターゲットの列</param>
void moveUp5x5(int arr[5][5], int column) {

	int temp = arr[0][column];  // 保存第一行的元素
	for (int i = 0; i < 4; i++) {
		arr[i][column] = arr[i + 1][column];  // 向上移动一位
	}
	arr[4][column] = temp;  // 将保存的元素移到最后一行

}

/// <summary>
/// 5x5 の2次元配列の列を下方向に移動する。
/// </summary>
/// <param name="arr">ターゲットの2次元配列</param>
/// <param name="column">ターゲットの列</param>
void moveDown5x5(int arr[5][5], int column) {

	int temp = arr[4][column];  // 保存第一行的元素
	for (int i = 4; i >= 1; i--) {
		arr[i][column] = arr[i - 1][column];  // 向上移动一位
	}
	arr[0][column] = temp;  // 将保存的元素移到最后一行

}

/// <summary>
/// 5x5 の2次元配列の行を左方向に移動する。
/// </summary>
/// <param name="array">ターゲットの2次元配列</param>
/// <param name="row">ターゲットの行</param>
void moveLeft5x5(int array[5][5], int row) {
	int temp = array[row][0]; // 保存第一行的第一个元素

	// 向左移动第一行的元素
	for (int i = 0; i < 4; i++) {
		array[row][i] = array[row][i + 1];
	}

	array[row][4] = temp; // 将保存的元素放到第一行的最后
}

/// <summary>
/// 5x5 の2次元配列の行を右方向に移動する。
/// </summary>
/// <param name="array">ターゲットの2次元配列</param>
/// <param name="row">ターゲットの行</param>
void moveRight5x5(int array[5][5], int row) {
	int temp = array[row][4]; // 保存第一行的最后一个元素

	// 向右移动第一行的元素
	for (int i = 4; i > 0; i--) {
		array[row][i] = array[row][i - 1];
	}

	array[row][0] = temp; // 将保存的元素放到第一行的第一个
}
#pragma endregion
#pragma region count

/// <summary>
/// 指定した数値の出現回数をカウントする関数
/// </summary>
/// <param name="arr">ターゲットの2次元配列</param>
/// <param name="target">ターゲットの数値</param>
/// <returns>出現回数</returns>
int countValue2x2(int arr[2][2], int target) {
	int count = 0;

	// 遍历二维数组，统计特定值的出现次数
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (arr[i][j] == target) {
				count++;
			}
		}
	}
	return count;
}
/// <summary>
/// 指定した数値の出現回数をカウントする関数
/// </summary>
/// <param name="arr">ターゲットの2次元配列</param>
/// <param name="target">ターゲットの数値</param>
/// <returns>出現回数</returns>
int countValue3x3(int arr[3][3], int target) {
	int count = 0;

	// 遍历二维数组，统计特定值的出现次数
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] == target) {
				count++;
			}
		}
	}
	return count;
}
#pragma endregion
/// <summary>
/// 6x10 の2次元配列を0にリセットする(6x10 矩阵 重置为0)
/// </summary>
/// <param name="arr">ターゲットの2次元配列</param>
void resetArr6x10to0(int arr[6][10]) {
	for (int y = 0; y < 6; y++) {
		for (int x = 0; x < 10; x++) {
			arr[y][x] = 0;
		}
	}
}
#pragma endregion
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	// 初始化随机数生成器
	srand((unsigned)time(NULL));
#pragma region start animation
	//image
	int startButton = Novice::LoadTexture("./Resources/Background/start.png");
	int startBkg = Novice::LoadTexture("./Resources/Background/startbkg.png");
	int chip = Novice::LoadTexture("./Resources/Battle/chip.png");
	///
	int countStartAni = 0;
	int countChip = 0;
	///
	float chipX = -128, chipY1 = 0, chipY2 = 0;

	float theta = float(M_PI);
	float amplitude = 20.0f;
#pragma endregion
#pragma region 音楽
	int Sound_Title = Novice::LoadAudio("./Resources/Sound/title_theme.wav");
	int Sound_Tutorial = Novice::LoadAudio("./Resources/Sound/tutorial_theme.wav");
	int Sound_Selection = Novice::LoadAudio("./Resources/Sound/selection_theme.wav");
	int Sound_Battle = Novice::LoadAudio("./Resources/Sound/battle_theme.wav");
	int Sound_Win = Novice::LoadAudio("./Resources/Sound/victory_theme.wav");
	int Sound_Lose = Novice::LoadAudio("./Resources/Sound/gameover_theme.wav");
	int Sound_Hit = Novice::LoadAudio("./Resources/Sound/hit_theme.wav");
	int Sound_Damage = Novice::LoadAudio("./Resources/Sound/damage_theme.wav");
	int Sound_Healing = Novice::LoadAudio("./Resources/Sound/healing_theme.wav");
	int Sound_Door = Novice::LoadAudio("./Resources/Sound/door_theme.wav");
	int voiceHandle_Title = -1;
	int voiceHandle_Tutorial = -1;
	int voiceHandle_Selection = -1;
	int voiceHandle_Battle = -1;
	int voiceHandle_Win = -1;
	int voiceHandle_Lose = -1;
	int voiceHandle_Hit = -1;
	int voiceHandle_Damage = -1;
	int voiceHandle_Healing = -1;
	int voiceHandle_Door = -1;


#pragma endregion
#pragma region 背景の画像
	//背景
	//int Texture_Title = Novice::LoadTexture("./Resources/Background/title.png");
	int Texture_Background = Novice::LoadTexture("./Resources/Background/bkg.png");
	int Texture_Win = Novice::LoadTexture("./Resources/Background/bkg_win.png");
	int Texture_Lose = Novice::LoadTexture("./Resources/Background/bkg_lose.png");
	int Texture_Door = Novice::LoadTexture("./Resources/Background/door.png");
	//Combat area の背景画像
	int Texture_BattleBG = Novice::LoadTexture("./Resources/Battle/battle.png");
	// door zoom
	float doorPosX = 0.0f;
	float doorPosY = 0.0f;
	float doorExpansion = 1.0f;
	int doorCountdown = 20;
	bool isDoorImageOver = false;
	bool isDoorZoomed = false;
	//stage 
	int Texture_StageSelection = Novice::LoadTexture("./Resources/Stage/bkg_stage.png");
	int Texture_StageNum1 = Novice::LoadTexture("./Resources/Stage/stage_num1.png");
	int Texture_StageNum2 = Novice::LoadTexture("./Resources/Stage/stage_num2.png");
#pragma endregion
#pragma region Scene
	//Scene
	enum Scene {
		TITLE,
		DOOR,
		ZOOMDOOR,
		stage0,//TUTORIAL
		selection,
		loading1,
		loading2,
		loadingWin,
		loadingDeath,
		stage1,
		stage2,
		win,
		death
	};
	Scene scene = TITLE;

	//stage
	enum StageSelection {
		nothing,
		stage01,
		stage02
	};
	StageSelection stageSelection = nothing;
#pragma endregion
#pragma region Selection box
	//4x4 Selection box 画像
	int Texture_Select4x4[2];
	Texture_Select4x4[0] = Novice::LoadTexture("./Resources/Battle/kuang1.png");
	Texture_Select4x4[1] = Novice::LoadTexture("./Resources/Battle/kuang2.png");
	//5x5 Selection box 画像
	int Texture_Select5x5[2];
	Texture_Select5x5[0] = Novice::LoadTexture("./Resources/Battle/kuang3.png");
	Texture_Select5x5[1] = Novice::LoadTexture("./Resources/Battle/kuang4.png");
	//Selection box Flag
	bool isHorizontal = true;
	//center
	int Texture_Center = Novice::LoadTexture("./Resources/Battle/center.png");
#pragma endregion
#pragma region loading

	int loading1Map[6][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
	};
	int loading1Timer = 0;
	int loading1row = 0;
	int loading1col = 0;

	int loading2Map[6][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
	};
	int loading2Timer = 0;
	int loading2row = 0;
	int loading2col = 0;

	int loadingWinMap[6][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
	};
	int loadingWinTimer = 0;
	int loadingWinrow = 0;
	int loadingWincol = 0;

	int loadingDeathMap[6][10] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0}
	};
	int loadingDeathTimer = 0;
	int loadingDeathrow = 0;
	int loadingDeathcol = 0;

	bool isLoading1Clear = false;
	bool isLoading2Clear = false;
	bool isLoadingWinClear = false;
	bool isLoadingDeathClear = false;
#pragma endregion
#pragma region 元素
	//元素の画像
	int Texture_Element = Novice::LoadTexture("./Resources/Battle/chip.png");

	//元素の二次元配列 初期化
	int elementMap4x4[4][4] = {
		{1,1,1,1},
		{2,2,2,2},
		{3,3,3,3},
		{4,4,4,4},
	};
	int elementMap5x5[5][5] = {
		{1,1,1,1,1},
		{2,2,2,2,2},
		{3,3,3,3,3},
		{4,4,4,4,4},
		{5,5,5,5,5}
	};
#pragma endregion
	//行列の変数
	int row = 0;
	int column = 0;
#pragma region timer
	//timerの画像
	int Texture_Timer[10];
	Texture_Timer[0] = Novice::LoadTexture("./Resources/Number/0.png");
	Texture_Timer[1] = Novice::LoadTexture("./Resources/Number/1.png");
	Texture_Timer[2] = Novice::LoadTexture("./Resources/Number/2.png");
	Texture_Timer[3] = Novice::LoadTexture("./Resources/Number/3.png");
	Texture_Timer[4] = Novice::LoadTexture("./Resources/Number/4.png");
	Texture_Timer[5] = Novice::LoadTexture("./Resources/Number/5.png");
	Texture_Timer[6] = Novice::LoadTexture("./Resources/Number/6.png");
	Texture_Timer[7] = Novice::LoadTexture("./Resources/Number/7.png");
	Texture_Timer[8] = Novice::LoadTexture("./Resources/Number/8.png");
	Texture_Timer[9] = Novice::LoadTexture("./Resources/Number/9.png");

	//桁数
	int eachTimerNumber[2] = {};
#pragma endregion
#pragma region 戦闘
#pragma region Combo
	int Texture_Combo_2 = Novice::LoadTexture("./Resources/Combo/2combo.png");
	int Texture_Combo_3 = Novice::LoadTexture("./Resources/Combo/3combo.png");
	int Texture_Combo_4 = Novice::LoadTexture("./Resources/Combo/4combo.png");
	int Texture_Combo_5 = Novice::LoadTexture("./Resources/Combo/5combo.png");
	int Texture_Combo_6 = Novice::LoadTexture("./Resources/Combo/6combo.png");
	int Texture_Combo_7 = Novice::LoadTexture("./Resources/Combo/7combo.png");
	int Texture_Combo_8 = Novice::LoadTexture("./Resources/Combo/8combo.png");
	int Texture_Combo_9 = Novice::LoadTexture("./Resources/Combo/9combo.png");
	int Texture_Combo_10 = Novice::LoadTexture("./Resources/Combo/10combo.png");

	int combo = 0;
#pragma endregion
#pragma region 時間
	//時間
	float stage1Timer = 30;
	float stage2Timer = 45;
#pragma endregion
#pragma region hit and shake

	//hit and shake (enemy)
	bool isHit = false;
	bool isShake = false;
	float frame = 0;
	int randX = 0;
	int randY = 0;

	//hit and shake (player)
	bool isPlayerHit = false;
	bool isPlayerShake = false;
	float framePlayeShake = 0;
	int randPlayeShakeX = 0;
	int randPlayeShakeY = 0;
#pragma endregion
#pragma region ターゲットの二次元配列
	//ターゲットの二次元配列 stage 1
	int targetMap1[2][2] = {
		{4,1},
		{3,2}
	};

	//判定結果を格納する2次元配列 stage 1
	int targetDetermineMap1[2][2] = {
		{0,0},
		{0,0}
	};
	//ターゲットの二次元配列 stage 2
	int targetMap2[3][3] = {
		{4,1,2},
		{3,2,4},
		{2,1,3}
	};
	//判定結果を格納する2次元配列 stage 2
	int targetDetermineMap2[3][3] = {
		{0,0,0},
		{0,0,0},
		{0,0,0}
	};
#pragma endregion
#pragma region information
	//player information
	Player player;
	player.pos.x = 0;
	player.pos.y = 0;
	player.width = 64;
	player.height = 64;
	player.hp = 50;
	player.maxHp = 50;
	player.atk = 10;

	//boss information
	Boss boss_1;
	boss_1.pos.x = 846;
	boss_1.pos.y = 50;
	boss_1.width = 64;
	boss_1.height = 64;
	boss_1.hp = 80;
	boss_1.maxHp = 80;
	boss_1.atk = 10;
	boss_1.advantage = 2;
	boss_1.weakness = 4;
	boss_1.texture = Novice::LoadTexture("./Resources/Enemy/slime.png");
	boss_1.texture_hit = Novice::LoadTexture("./Resources/Enemy/slime_hit.png");
	int Texture_Boss1 = Novice::LoadTexture("./Resources/Enemy/slime1.png");
	Boss boss_2;
	boss_2.pos.x = 846;
	boss_2.pos.y = 50;
	boss_2.width = 64;
	boss_2.height = 64;
	boss_2.hp = 70;
	boss_2.maxHp = 70;
	boss_2.atk = 10;
	boss_2.advantage = 1;
	boss_2.weakness = 3;
	boss_2.texture = Novice::LoadTexture("./Resources/Enemy/ghost.png");
	boss_2.texture_hit = Novice::LoadTexture("./Resources/Enemy/ghost_hit.png");
	int Texture_Boss2 = Novice::LoadTexture("./Resources/Enemy/ghost1.png");
#pragma endregion
#pragma region enemy 行為
	int slimeTimer = 0;
	int slimeMovement = 0;
	int slimeDraw = 0;
	int ghostTimer = 0;
	int ghostMovement = 0;
	int ghostDraw = 0;
#pragma endregion
	//勝敗Flag
	bool isSuccess = false;
	//ダメージ倍率補正
	float damageCorrection = 1.0f;
#pragma endregion
#pragma region Tutorial
	//画像 stage 0
	int Texture_Tutorial[17];
	Texture_Tutorial[0] = Novice::LoadTexture("./Resources/Tutorial/1.png");
	Texture_Tutorial[1] = Novice::LoadTexture("./Resources/Tutorial/2.png");
	Texture_Tutorial[2] = Novice::LoadTexture("./Resources/Tutorial/3.png");
	Texture_Tutorial[3] = Novice::LoadTexture("./Resources/Tutorial/4.png");
	Texture_Tutorial[4] = Novice::LoadTexture("./Resources/Tutorial/5.png");
	Texture_Tutorial[5] = Novice::LoadTexture("./Resources/Tutorial/6.png");
	Texture_Tutorial[6] = Novice::LoadTexture("./Resources/Tutorial/7.png");
	Texture_Tutorial[7] = Novice::LoadTexture("./Resources/Tutorial/8.png");
	Texture_Tutorial[8] = Novice::LoadTexture("./Resources/Tutorial/9.png");
	Texture_Tutorial[9] = Novice::LoadTexture("./Resources/Tutorial/10.png");
	Texture_Tutorial[10] = Novice::LoadTexture("./Resources/Tutorial/11.png");
	Texture_Tutorial[11] = Novice::LoadTexture("./Resources/Tutorial/12.png");
	Texture_Tutorial[12] = Novice::LoadTexture("./Resources/Tutorial/13.png");
	Texture_Tutorial[13] = Novice::LoadTexture("./Resources/Tutorial/14.png");
	Texture_Tutorial[14] = Novice::LoadTexture("./Resources/Tutorial/15.png");
	Texture_Tutorial[15] = Novice::LoadTexture("./Resources/Tutorial/16.png");
	Texture_Tutorial[16] = Novice::LoadTexture("./Resources/Tutorial/17.png");
	//timer stage 0
	float stage0Timer = 3;
	//元素の二次元配列 stage 0
	int tutorialMap4x4[4][4] = {
		{1,2,3,4},
		{2,1,4,3},
		{3,4,1,2},
		{4,3,2,1},
	};
	//ターゲットの二次元配列 stage 0
	int targetMap0[2][2] = {
		{4,1},
		{3,2}
	};
	//判定結果を格納する2次元配列 stage 0
	int targetDetermineMap0[2][2] = {
		{0,0},
		{0,0}
	};
	//Tutorial flag
	int stepNum = 0;
	bool isStep0Clear = false;
	bool isStep1Clear = false;
	bool isStep2Clear = false;
	bool isStep3Clear = false;
	bool isStep3_1Clear = false;
	bool isStep3_2Clear = false;
	bool isStep4Clear = false;
	bool isStep5Clear = false;
	bool isStep6Clear = false;
	bool isStep7Clear = false;
	bool isStep7_1Clear = false;
	bool isStep7_2Clear = false;
	bool isStep8Clear = false;
	bool isStep9Clear = false;
	bool isStep10Clear = false;
	int step10Step = 0;
	bool isStep11Clear = false;
	bool isStep12Clear = false;
	bool isStep13Clear = false;
	bool isTutorialComplete = false;
#pragma endregion
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
#pragma region Tutorial
		if (scene == TITLE) {
			Novice::StopAudio(voiceHandle_Tutorial);
			Novice::StopAudio(voiceHandle_Selection);
			Novice::StopAudio(voiceHandle_Battle);
			Novice::StopAudio(voiceHandle_Win);
			Novice::StopAudio(voiceHandle_Lose);
			if (Novice::IsPlayingAudio(voiceHandle_Title) == 0 || voiceHandle_Title == -1) {
				voiceHandle_Title = Novice::PlayAudio(Sound_Title, true, 0.5f);
			}
#pragma region start animation
			chipY1 = (sinf(theta) * amplitude) + 592;
			chipY2 = (cosf(theta) * amplitude) + 592;
			theta += float(M_PI) / 30.0f;
#pragma endregion
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				scene = DOOR;
				voiceHandle_Door = Novice::PlayAudio(Sound_Door, false, 1.0f);
			}
		}
		if (scene == DOOR) {
			if (isDoorImageOver == false) {
				doorCountdown--;
			}
			if (doorCountdown <= 0) {
				isDoorImageOver = true;
			}
			if (isDoorImageOver == true) {
				scene = ZOOMDOOR;
				doorCountdown = 20;
				isDoorImageOver = false;
			}
		}
		if (scene == ZOOMDOOR) {
			if (doorPosX > -4600.0f) {
				doorPosX -= 160.0f;
			}
			if (doorPosY > -2400.0f) {
				doorPosY -= 84.0f;
			}
			if (doorExpansion < 8.0f) {
				doorExpansion += 0.25f;
			}
			if (doorPosX <= -4600.0f && doorPosY <= -2400.0f && doorExpansion >= 8.0f) {
				isDoorZoomed = true;
			}
			if (isDoorZoomed == true) {
				isStep0Clear = true;
				stepNum++;
				scene = stage0;
				doorPosX = 0.0f;
				doorPosY = 0.0f;
				doorExpansion = 1.0f;
				isDoorZoomed = false;
			}
		}
		if (scene == stage0) {
			Novice::StopAudio(voiceHandle_Title);
			Novice::StopAudio(voiceHandle_Selection);
			Novice::StopAudio(voiceHandle_Battle);
			Novice::StopAudio(voiceHandle_Win);
			Novice::StopAudio(voiceHandle_Lose);
			if (Novice::IsPlayingAudio(voiceHandle_Tutorial) == 0 || voiceHandle_Tutorial == -1) {
				voiceHandle_Tutorial = Novice::PlayAudio(Sound_Tutorial, true, 0.5f);
			}
			if (keys[DIK_Z] && preKeys[DIK_Z] == 0) { //skip Tutorial
				scene = selection;
				isTutorialComplete = true;
			}
			switch (stepNum) {
				case 1:
					if (isHorizontal) {
						if (keys[DIK_S] && preKeys[DIK_S] == 0) {
							if (row < 3) {
								row++;
							}
						}
					}
					if (keys[DIK_S] && preKeys[DIK_S] == 0) {
						isStep1Clear = true;
						stepNum++;
					}
					break;
				case 2:
					if (keys[DIK_W] && preKeys[DIK_W] == 0) {
						isStep2Clear = true;
						stepNum++;
					}
					if (isHorizontal) {
						if (keys[DIK_W] && preKeys[DIK_W] == 0) {
							if (row > 0) {
								row--;
							}
						}
					}
					break;
				case 3:
					if (isHorizontal) {
						if (keys[DIK_A] && preKeys[DIK_A] == 0) {
							moveLeft4x4(tutorialMap4x4, row);
							isStep3_1Clear = true;
						}
						if (keys[DIK_D] && preKeys[DIK_D] == 0) {
							moveRight4x4(tutorialMap4x4, row);
							isStep3_2Clear = true;
						}
					}
					if (isStep3_1Clear && isStep3_2Clear) {
						isStep3Clear = true;
						stepNum++;
					}
					break;
				case 4:
					if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
						isHorizontal = !isHorizontal;
					}
					if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
						isStep4Clear = true;
						stepNum++;
					}
					break;
				case 5:
					if (!isHorizontal) {
						if (keys[DIK_D] && preKeys[DIK_D] == 0) {
							if (column < 3) {
								column++;
							}
						}
					}
					if (keys[DIK_D] && preKeys[DIK_D] == 0) {
						isStep5Clear = true;
						stepNum++;
					}
					break;
				case 6:
					if (!isHorizontal) {
						if (keys[DIK_A] && preKeys[DIK_A] == 0) {
							if (column > 0) {
								column--;
							}
						}
					}
					if (keys[DIK_A] && preKeys[DIK_A] == 0) {
						isStep6Clear = true;
						stepNum++;
					}
					break;
				case 7:
					if (!isHorizontal) {
						if (keys[DIK_W] && preKeys[DIK_W] == 0) {
							moveUp4x4(tutorialMap4x4, column);
							isStep7_1Clear = true;
						}
						if (keys[DIK_S] && preKeys[DIK_S] == 0) {
							moveDown4x4(tutorialMap4x4, column);
							isStep7_2Clear = true;
						}
					}
					if (isStep7_1Clear && isStep7_2Clear) {
						isStep7Clear = true;
						stepNum++;
					}
					break;
				case 8:
					//水平 垂直 スイッチ
					if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
						isHorizontal = !isHorizontal;
					}
#pragma region ボックス 移動

					if (isHorizontal) {
						if (keys[DIK_W] && preKeys[DIK_W] == 0) {
							if (row > 0) {
								row--;
							}
						}
						if (keys[DIK_S] && preKeys[DIK_S] == 0) {
							if (row < 3) {
								row++;
							}
						}
					}
					if (!isHorizontal) {
						if (keys[DIK_A] && preKeys[DIK_A] == 0) {
							if (column > 0) {
								column--;
							}
						}
						if (keys[DIK_D] && preKeys[DIK_D] == 0) {
							if (column < 3) {
								column++;
							}
						}
					}
#pragma endregion
#pragma region 元素 移動
					if (!isHorizontal) {
						if (keys[DIK_W] && preKeys[DIK_W] == 0) {
							moveUp4x4(tutorialMap4x4, column);
						}
						if (keys[DIK_S] && preKeys[DIK_S] == 0) {
							moveDown4x4(tutorialMap4x4, column);
						}
					}
					if (isHorizontal) {
						if (keys[DIK_A] && preKeys[DIK_A] == 0) {
							moveLeft4x4(tutorialMap4x4, row);
						}
						if (keys[DIK_D] && preKeys[DIK_D] == 0) {
							moveRight4x4(tutorialMap4x4, row);
						}
					}
#pragma endregion
#pragma region 中心判断
					//中心の数値を判断の二次元配列に格納する
					if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
						targetDetermineMap0[0][0] = tutorialMap4x4[1][1];
						targetDetermineMap0[0][1] = tutorialMap4x4[1][2];
						targetDetermineMap0[1][0] = tutorialMap4x4[2][1];
						targetDetermineMap0[1][1] = tutorialMap4x4[2][2];
					}
					//判断
					if (targetDetermineMap0[0][0] == targetMap0[0][0] &&
						targetDetermineMap0[0][1] == targetMap0[0][1] &&
						targetDetermineMap0[1][0] == targetMap0[1][0] &&
						targetDetermineMap0[1][1] == targetMap0[1][1]) {
						boss_1.hp -= player.atk;
						isStep8Clear = true;
						stepNum++;
					}
#pragma endregion
					break;
				case 9:
					if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
						isStep9Clear = true;
						stepNum++;
					}
					break;
				case 10:
					if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
						step10Step++;
					}
					if (step10Step > 3) {
						isStep10Clear = true;
						stepNum++;
					}
					break;
				case 11:
					if (keys[DIK_K] && preKeys[DIK_K] == 0) {
						for (int i = 0; i < 2; i++) {
							for (int j = 0; j < 2; j++) {
								targetMap0[i][j] = rand() % 4 + 1; // 生成1到4之间的随机数
							}
						}
						player.hp -= boss_1.atk / 2;
						combo = 0;
						isStep11Clear = true;
						stepNum++;
					}
					break;
				case 12:
					//=============================================
					// Timer
					//=============================================
					//十位
					eachTimerNumber[0] = static_cast<int>(stage0Timer) % 100 / 10;
					//个位
					eachTimerNumber[1] = static_cast<int>(stage0Timer) % 10;
					stage0Timer -= 1.0f / 60;
					if (stage0Timer < 0) {
						stage0Timer = 0;
					}
					if (stage0Timer == 0) {
						player.hp -= boss_1.atk;
						isStep12Clear = true;
						stepNum++;
					}
					break;
				case 13:
					if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
						player.hp += 10;
						isStep13Clear = true;
						stepNum++;
					}

					break;
				case 14:
					if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
						scene = selection;
						isTutorialComplete = true;
					}
					break;
			}
		}
		if (isTutorialComplete) {
			tutorialMap4x4[0][0] = 1;
			tutorialMap4x4[0][1] = 2;
			tutorialMap4x4[0][2] = 3;
			tutorialMap4x4[0][3] = 4;
			tutorialMap4x4[1][0] = 2;
			tutorialMap4x4[1][1] = 1;
			tutorialMap4x4[1][2] = 4;
			tutorialMap4x4[1][3] = 3;
			tutorialMap4x4[2][0] = 3;
			tutorialMap4x4[2][1] = 4;
			tutorialMap4x4[2][2] = 1;
			tutorialMap4x4[2][3] = 2;
			tutorialMap4x4[3][0] = 4;
			tutorialMap4x4[3][1] = 3;
			tutorialMap4x4[3][2] = 2;
			tutorialMap4x4[3][3] = 1;
			targetMap0[0][0] = 4;
			targetMap0[0][1] = 1;
			targetMap0[1][0] = 3;
			targetMap0[1][1] = 2;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					targetDetermineMap0[j][i] = 0;
				}
			}
			stage0Timer = 3;
			player.hp = player.maxHp;
			boss_1.hp = boss_1.maxHp;
			stepNum = 0;
			isStep0Clear = false;
			isStep1Clear = false;
			isStep2Clear = false;
			isStep3Clear = false;
			isStep3_1Clear = false;
			isStep3_2Clear = false;
			isStep4Clear = false;
			isStep5Clear = false;
			isStep6Clear = false;
			isStep7Clear = false;
			isStep7_1Clear = false;
			isStep7_2Clear = false;
			isStep8Clear = false;
			isStep9Clear = false;
			isStep10Clear = false;
			step10Step = 0;
			isStep11Clear = false;
			isStep12Clear = false;
			isStep13Clear = false;
			isHorizontal = true;
			isTutorialComplete = !isTutorialComplete;
		}
#pragma endregion
#pragma region stage 選択
		if (scene == selection) {
			Novice::StopAudio(voiceHandle_Title);
			Novice::StopAudio(voiceHandle_Tutorial);
			Novice::StopAudio(voiceHandle_Battle);
			Novice::StopAudio(voiceHandle_Win);
			Novice::StopAudio(voiceHandle_Lose);
			if (Novice::IsPlayingAudio(voiceHandle_Selection) == 0 || voiceHandle_Selection == -1) {
				voiceHandle_Selection = Novice::PlayAudio(Sound_Selection, true, 0.5f);
			}
			//stage 選択
			if (stageSelection == nothing) {
				if ((keys[DIK_A] && preKeys[DIK_A] == 0) || (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)) {
					stageSelection = stage01;
				}
				if ((keys[DIK_D] && preKeys[DIK_D] == 0) || (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)) {
					stageSelection = stage02;
				}
			}
			if (stageSelection == stage01) {
				if ((keys[DIK_D] && preKeys[DIK_D] == 0) || (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)) {
					stageSelection = stage02;
				}
			}
			if (stageSelection == stage02) {
				if ((keys[DIK_A] && preKeys[DIK_A] == 0) || (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)) {
					stageSelection = stage01;
				}
			}
			if (stageSelection == stage01 && (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0)) {
				//scene = stage1;
				scene = loading1;
				stageSelection = nothing;
				stage1Timer = 30;
				player.hp = player.maxHp;
				boss_1.hp = boss_1.maxHp;
				combo = 0;
				row = 0;
				column = 0;
				isSuccess = false;
			}
			if (stageSelection == stage02 && (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0)) {
				//scene = stage2;
				scene = loading2;
				stageSelection = nothing;
				stage2Timer = 45;
				player.hp = player.maxHp;
				boss_2.hp = boss_2.maxHp;
				combo = 0;
				row = 0;
				column = 0;
				isSuccess = false;
			}
		}
#pragma endregion
#pragma region loading
		if (scene == loading1 && !isLoading1Clear) {
			if (loading1Map[5][9] == 0) {
				loading1Timer++;
				if (loading1Timer == 2) {
					loading1Map[loading1col][loading1row] = rand() % 5 + 1;
					loading1row++;
					loading1Timer = 0;
				}
				if (loading1row > 9) {
					loading1row = 0;
					loading1col++;
				}
			}
			else {
				isLoading1Clear = true;
			}
		}

		if (scene == loading2 && !isLoading2Clear) {
			if (loading2Map[5][9] == 0) {
				loading2Timer++;
				if (loading2Timer == 2) {
					loading2Map[loading2col][loading2row] = rand() % 5 + 1;
					loading2row++;
					loading2Timer = 0;
				}
				if (loading2row > 9) {
					loading2row = 0;
					loading2col++;
				}
			}
			else {
				isLoading2Clear = true;
			}
		}



		if (isLoading1Clear) {
			scene = stage1;
			resetArr6x10to0(loading1Map);
			loading1Timer = 0;
			loading1row = 0;
			loading1col = 0;
			isLoading1Clear = false;
		}
		if (isLoading2Clear) {
			scene = stage2;
			resetArr6x10to0(loading2Map);
			loading2Timer = 0;
			loading2row = 0;
			loading2col = 0;
			isLoading2Clear = false;
		}

#pragma endregion
		/*if (keys[DIK_1] && preKeys[DIK_1] == 0) {
			player.hp -= 500;
		}
		if (keys[DIK_2] && preKeys[DIK_2] == 0) {
			player.hp -= 500;
		}
		if (keys[DIK_3] && preKeys[DIK_3] == 0) {
			boss_1.hp -= 500;
		}
		if (keys[DIK_4] && preKeys[DIK_4] == 0) {
			boss_2.hp -= 500;
		}*/
#pragma region stage 1

		if (scene == stage1) {
			Novice::StopAudio(voiceHandle_Title);
			Novice::StopAudio(voiceHandle_Tutorial);
			Novice::StopAudio(voiceHandle_Selection);
			Novice::StopAudio(voiceHandle_Win);
			Novice::StopAudio(voiceHandle_Lose);
			if (Novice::IsPlayingAudio(voiceHandle_Battle) == 0 || voiceHandle_Battle == -1) {
				voiceHandle_Battle = Novice::PlayAudio(Sound_Battle, true, 0.2f);
			}
			//Reset
			if (keys[DIK_R] && preKeys[DIK_R] == 0) {
				resetArr4x4(elementMap4x4);
			}
			//ボックス 水平と垂直 スイッチ
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				isHorizontal = !isHorizontal;
			}
#pragma region ボックス 移動

			if (isHorizontal) {
				if (keys[DIK_W] && preKeys[DIK_W] == 0) {
					if (row > 0) {
						row--;
					}
				}
				if (keys[DIK_S] && preKeys[DIK_S] == 0) {
					if (row < 3) {
						row++;
					}
				}
			}
			if (!isHorizontal) {
				if (keys[DIK_A] && preKeys[DIK_A] == 0) {
					if (column > 0) {
						column--;
					}
				}
				if (keys[DIK_D] && preKeys[DIK_D] == 0) {
					if (column < 3) {
						column++;
					}
				}
			}
#pragma endregion
#pragma region 元素 移動

			if (!isHorizontal) {
				if (keys[DIK_W] && preKeys[DIK_W] == 0) {
					moveUp4x4(elementMap4x4, column);
				}
				if (keys[DIK_S] && preKeys[DIK_S] == 0) {
					moveDown4x4(elementMap4x4, column);
				}
			}
			if (isHorizontal) {
				if (keys[DIK_A] && preKeys[DIK_A] == 0) {
					moveLeft4x4(elementMap4x4, row);
				}
				if (keys[DIK_D] && preKeys[DIK_D] == 0) {
					moveRight4x4(elementMap4x4, row);
				}
			}
#pragma endregion
#pragma region 戦闘

			//timer
			//十位
			eachTimerNumber[0] = static_cast<int>(stage1Timer) % 100 / 10;
			//个位
			eachTimerNumber[1] = static_cast<int>(stage1Timer) % 10;
			stage1Timer -= 1.0f / 60;
			if (stage1Timer < 0) {
				stage1Timer = 0;
			}
			//中心の数値を判断の二次元配列に格納する
			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
				targetDetermineMap1[0][0] = elementMap4x4[1][1];
				targetDetermineMap1[0][1] = elementMap4x4[1][2];
				targetDetermineMap1[1][0] = elementMap4x4[2][1];
				targetDetermineMap1[1][1] = elementMap4x4[2][2];
			}
			//判断
			if (targetDetermineMap1[0][0] == targetMap1[0][0] &&
				targetDetermineMap1[0][1] == targetMap1[0][1] &&
				targetDetermineMap1[1][0] == targetMap1[1][0] &&
				targetDetermineMap1[1][1] == targetMap1[1][1]) {
				isSuccess = true;
			}
			//優勢な元素と弱い元素の数を数える
			int resultAdvantage1 = countValue2x2(targetMap1, boss_1.advantage);
			int resultWeakness1 = countValue2x2(targetMap1, boss_1.weakness);

			//ダメージ倍率補正
			if (resultAdvantage1 - resultWeakness1 > 0) {
				damageCorrection = 0.8f;
			}
			if (resultAdvantage1 - resultWeakness1 == 0) {
				damageCorrection = 1.0f;
			}
			if (resultAdvantage1 - resultWeakness1 < 0) {
				damageCorrection = 1.2f;
			}
			if (isSuccess) {
				//新しい2次元配列をランダムに生成する
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						targetMap1[i][j] = rand() % 4 + 1; // 1~4の乱数を生成する
					}
				}
				//resetArr4x4(elementMap4x4);
				combo++;
				boss_1.hp -= player.atk * damageCorrection;
				voiceHandle_Hit = Novice::PlayAudio(Sound_Hit, false, 1.0f);
				isHit = true;
				frame = 30;
				stage1Timer = 30;
				isSuccess = false;
				if (combo % 4 == 0) {
					if (player.hp + 10 > player.maxHp) {
						player.hp += player.maxHp - player.hp;
						voiceHandle_Healing = Novice::PlayAudio(Sound_Healing, false, 1.0f);
					}
					else {
						player.hp += 10;
						voiceHandle_Healing = Novice::PlayAudio(Sound_Healing, false, 1.0f);
					}
				}
			}
			//hit and shake
			if (isHit) {
				if (frame < 0) {
					frame = 0;
				}
				else {
					frame--;
				}
				isShake = !isShake;
				if (isShake) {
					if (frame > 20 && frame <= 30) {
						randX = rand() % 41 - 20;
						randY = rand() % 41 - 20;
					}
					if (frame > 10 && frame <= 20) {
						randX = rand() % 21 - 10;
						randY = rand() % 21 - 10;
					}
					if (frame > 0 && frame <= 10) {
						randX = rand() % 11 - 5;
						randY = rand() % 11 - 5;
					}
					if (frame == 0) {
						randX = 0;
						randY = 0;
					}
				}
			}
			if (boss_1.hp <= 0) {
				scene = loadingWin;
				isLoadingWinClear = false;
			}
			if (stage1Timer == 0) {
				player.hp -= boss_1.atk;
				voiceHandle_Damage = Novice::PlayAudio(Sound_Damage, false, 1.0f);
				combo = 0;
				isPlayerHit = true;
				framePlayeShake = 30;
				stage1Timer = 30;
			}
			if (isPlayerHit) {
				if (framePlayeShake < 0) {
					framePlayeShake = 0;
				}
				else {
					framePlayeShake--;
				}
				isPlayerShake = !isPlayerShake;
				if (isPlayerShake) {
					if (framePlayeShake > 20 && framePlayeShake <= 30) {
						randPlayeShakeX = rand() % 41 - 20;
						randPlayeShakeY = rand() % 41 - 20;
					}
					if (framePlayeShake > 10 && framePlayeShake <= 20) {
						randPlayeShakeX = rand() % 21 - 10;
						randPlayeShakeY = rand() % 21 - 10;
					}
					if (framePlayeShake > 0 && framePlayeShake <= 10) {
						randPlayeShakeX = rand() % 11 - 5;
						randPlayeShakeY = rand() % 11 - 5;
					}
					if (framePlayeShake == 0) {
						randPlayeShakeX = 0;
						randPlayeShakeY = 0;
						isPlayerHit = false;
					}
				}
			}
			if (keys[DIK_K] && preKeys[DIK_K] == 0) {
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						targetMap1[i][j] = rand() % 4 + 1; // 1~4の乱数を生成する
					}
				}
				player.hp -= boss_1.atk / 2;
				combo = 0;
			}
			if (player.hp <= 0) {
				player.hp = 0;
				scene = loadingDeath;
				isLoadingDeathClear = false;
			}
#pragma endregion
#pragma region enemy 行為
			///
			slimeTimer++;

			if (slimeTimer >= 15) {
				slimeTimer = 0;
				slimeMovement++;
			}
			slimeDraw = slimeMovement * 384;
			if (slimeMovement >= 4) {
				slimeMovement = 0;
			}
#pragma endregion
		}
#pragma endregion
#pragma region stage 2
		if (scene == stage2) {
			Novice::StopAudio(voiceHandle_Title);
			Novice::StopAudio(voiceHandle_Tutorial);
			Novice::StopAudio(voiceHandle_Selection);
			Novice::StopAudio(voiceHandle_Win);
			Novice::StopAudio(voiceHandle_Lose);
			if (Novice::IsPlayingAudio(voiceHandle_Battle) == 0 || voiceHandle_Battle == -1) {
				voiceHandle_Battle = Novice::PlayAudio(Sound_Battle, true, 0.2f);
			}

			//Reset
			if (keys[DIK_R] && preKeys[DIK_R] == 0) {
				resetArr5x5(elementMap5x5);
			}
			//ボックス 水平と垂直 スイッチ
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				isHorizontal = !isHorizontal;
			}

#pragma region ボックス 移動

			if (isHorizontal) {
				if (keys[DIK_W] && preKeys[DIK_W] == 0) {
					if (row > 0) {
						row--;
					}
				}
				if (keys[DIK_S] && preKeys[DIK_S] == 0) {
					if (row < 4) {
						row++;
					}
				}
			}
			if (!isHorizontal) {
				if (keys[DIK_A] && preKeys[DIK_A] == 0) {
					if (column > 0) {
						column--;
					}
				}
				if (keys[DIK_D] && preKeys[DIK_D] == 0) {
					if (column < 4) {
						column++;
					}
				}
			}
#pragma endregion
#pragma region 元素 移動

			if (!isHorizontal) {
				if (keys[DIK_W] && preKeys[DIK_W] == 0) {
					moveUp5x5(elementMap5x5, column);
				}
				if (keys[DIK_S] && preKeys[DIK_S] == 0) {
					moveDown5x5(elementMap5x5, column);
				}
			}
			if (isHorizontal) {
				if (keys[DIK_A] && preKeys[DIK_A] == 0) {
					moveLeft5x5(elementMap5x5, row);
				}
				if (keys[DIK_D] && preKeys[DIK_D] == 0) {
					moveRight5x5(elementMap5x5, row);
				}
			}
#pragma endregion
#pragma region 戦闘
			//timer
			//十位
			eachTimerNumber[0] = static_cast<int>(stage2Timer) % 100 / 10;
			//个位
			eachTimerNumber[1] = static_cast<int>(stage2Timer) % 10;
			stage2Timer -= 1.0f / 60;
			if (stage2Timer < 0) {
				stage2Timer = 0;
			}
			//中心の数値を判断の二次元配列に格納する
			if (keys[DIK_RETURN] && preKeys[DIK_RETURN] == 0) {
				targetDetermineMap2[0][0] = elementMap5x5[1][1];
				targetDetermineMap2[0][1] = elementMap5x5[1][2];
				targetDetermineMap2[0][2] = elementMap5x5[1][3];
				targetDetermineMap2[1][0] = elementMap5x5[2][1];
				targetDetermineMap2[1][1] = elementMap5x5[2][2];
				targetDetermineMap2[1][2] = elementMap5x5[2][3];
				targetDetermineMap2[2][0] = elementMap5x5[3][1];
				targetDetermineMap2[2][1] = elementMap5x5[3][2];
				targetDetermineMap2[2][2] = elementMap5x5[3][3];
			}
			//判断
			if (targetDetermineMap2[0][0] == targetMap2[0][0] &&
				targetDetermineMap2[0][1] == targetMap2[0][1] &&
				targetDetermineMap2[0][2] == targetMap2[0][2] &&
				targetDetermineMap2[1][0] == targetMap2[1][0] &&
				targetDetermineMap2[1][1] == targetMap2[1][1] &&
				targetDetermineMap2[1][2] == targetMap2[1][2] &&
				targetDetermineMap2[2][0] == targetMap2[2][0] &&
				targetDetermineMap2[2][1] == targetMap2[2][1] &&
				targetDetermineMap2[2][2] == targetMap2[2][2]) {
				isSuccess = true;
			}
			//優勢な元素と弱い元素の数を数える
			int resultAdvantage2 = countValue3x3(targetMap2, boss_2.advantage);
			int resultWeakness2 = countValue3x3(targetMap2, boss_2.weakness);

			//ダメージ倍率補正
			if (resultAdvantage2 - resultWeakness2 > 0) {
				damageCorrection = 0.8f;
			}
			if (resultAdvantage2 - resultWeakness2 == 0) {
				damageCorrection = 1.0f;
			}
			if (resultAdvantage2 - resultWeakness2 < 0) {
				damageCorrection = 1.2f;
			}

			//hit and shake
			if (isHit) {
				if (frame < 0) {
					frame = 0;
				}
				else {
					frame--;
				}
				isShake = !isShake;
				if (isShake) {
					if (frame > 20 && frame <= 30) {
						randX = rand() % 41 - 20;
						randY = rand() % 41 - 20;
					}
					if (frame > 10 && frame <= 20) {
						randX = rand() % 21 - 10;
						randY = rand() % 21 - 10;
					}
					if (frame > 0 && frame <= 10) {
						randX = rand() % 11 - 5;
						randY = rand() % 11 - 5;
					}
					if (frame == 0) {
						randX = 0;
						randY = 0;
						isHit = false;
					}
				}
			}
			if (isSuccess) {
				// 新しい2次元配列をランダムに生成する
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						targetMap2[i][j] = rand() % 5 + 1; // 1~4の乱数を生成する
					}
				}
				//resetArr5x5(elementMap5x5);
				combo++;
				boss_2.hp -= player.atk * damageCorrection;
				voiceHandle_Hit = Novice::PlayAudio(Sound_Hit, false, 1.0f);
				isHit = true;
				frame = 30;
				stage2Timer = 45;
				isSuccess = false;
				if (combo % 4 == 0) {
					if (player.hp + 10 > player.maxHp) {
						player.hp += player.maxHp - player.hp;
						voiceHandle_Healing = Novice::PlayAudio(Sound_Healing, false, 1.0f);
					}
					else {
						player.hp += 10;
						voiceHandle_Healing = Novice::PlayAudio(Sound_Healing, false, 1.0f);
					}
				}
			}
			if (boss_2.hp <= 0) {
				scene = loadingWin;
				isLoadingWinClear = false;
			}
			if (stage2Timer == 0) {
				player.hp -= boss_2.atk;
				voiceHandle_Damage = Novice::PlayAudio(Sound_Damage, false, 1.0f);
				combo = 0;
				isPlayerHit = true;
				framePlayeShake = 30;
				stage2Timer = 45;
			}
			if (isPlayerHit) {
				if (framePlayeShake < 0) {
					framePlayeShake = 0;
				}
				else {
					framePlayeShake--;
				}
				isPlayerShake = !isPlayerShake;
				if (isPlayerShake) {
					if (framePlayeShake > 20 && framePlayeShake <= 30) {
						randPlayeShakeX = rand() % 41 - 20;
						randPlayeShakeY = rand() % 41 - 20;
					}
					if (framePlayeShake > 10 && framePlayeShake <= 20) {
						randPlayeShakeX = rand() % 21 - 10;
						randPlayeShakeY = rand() % 21 - 10;
					}
					if (framePlayeShake > 0 && framePlayeShake <= 10) {
						randPlayeShakeX = rand() % 11 - 5;
						randPlayeShakeY = rand() % 11 - 5;
					}
					if (framePlayeShake == 0) {
						randPlayeShakeX = 0;
						randPlayeShakeY = 0;
						isPlayerHit = false;
					}
				}
			}
			if (keys[DIK_K] && preKeys[DIK_K] == 0) {
				int counts[5] = { 0 };
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						int num;
						do {
							// 1~5の乱数を生成する
							num = rand() % 5 + 1;
						} while (counts[num - 1] >= 5); // 检查数字出现次数

						// 将选中的数字赋值给数组元素
						targetMap2[i][j] = num;
						// 增加相应数字的出现次数
						counts[num - 1]++;
					}
				}
				player.hp -= boss_2.atk / 2;
				combo = 0;
			}
			if (player.hp <= 0) {
				player.hp = 0;
				scene = loadingDeath;
				isLoadingDeathClear = false;
			}
#pragma endregion
#pragma region enemy 行為
			///
			///
			ghostTimer++;

			if (ghostTimer >= 15) {
				ghostTimer = 0;
				ghostMovement++;
			}
			ghostDraw = ghostMovement * 384;
			if (ghostMovement >= 4) {
				ghostMovement = 0;
			}
#pragma endregion
		}
#pragma endregion
#pragma region win or death loading

		if (scene == loadingWin && !isLoadingWinClear) {
			if (loadingWinMap[5][9] == 0) {
				loadingWinTimer++;
				if (loadingWinTimer == 2) {
					loadingWinMap[loadingWincol][loadingWinrow] = rand() % 5 + 1;
					loadingWinrow++;
					loadingWinTimer = 0;
				}
				if (loadingWinrow > 9) {
					loadingWinrow = 0;
					loadingWincol++;
				}
			}
			else {
				isLoadingWinClear = true;
			}
		}

		if (scene == loadingDeath && !isLoadingDeathClear) {
			if (loadingDeathMap[5][9] == 0) {
				loadingDeathTimer++;
				if (loadingDeathTimer == 2) {
					loadingDeathMap[loadingDeathcol][loadingDeathrow] = rand() % 5 + 1;
					loadingDeathrow++;
					loadingDeathTimer = 0;
				}
				if (loadingDeathrow > 9) {
					loadingDeathrow = 0;
					loadingDeathcol++;
				}
			}
			else {
				isLoadingDeathClear = true;
			}
		}



		if (isLoadingWinClear) {
			scene = win;
			resetArr6x10to0(loadingWinMap);
			loadingWinTimer = 0;
			loadingWinrow = 0;
			loadingWincol = 0;
			isLoadingWinClear = false;
		}
		if (isLoadingDeathClear) {
			scene = death;
			resetArr6x10to0(loadingDeathMap);
			loadingDeathTimer = 0;
			loadingDeathrow = 0;
			loadingDeathcol = 0;
			isLoadingDeathClear = false;
		}
#pragma endregion
#pragma region 勝敗
		if (scene == death) {
			//音楽
			Novice::StopAudio(voiceHandle_Title);
			Novice::StopAudio(voiceHandle_Tutorial);
			Novice::StopAudio(voiceHandle_Selection);
			Novice::StopAudio(voiceHandle_Battle);
			Novice::StopAudio(voiceHandle_Win);
			if (Novice::IsPlayingAudio(voiceHandle_Lose) == 0 || voiceHandle_Lose == -1) {
				voiceHandle_Lose = Novice::PlayAudio(Sound_Lose, true, 0.5f);
			}
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				scene = TITLE;
				player.hp = player.maxHp;
				boss_1.hp = boss_1.maxHp;
				row = 0;
				column = 0;
				isHorizontal = true;
				isHit = false;
				frame = 0;
				isPlayerHit = false;
				framePlayeShake = 0;
				resetArr4x4(elementMap4x4);
				resetArr5x5(elementMap5x5);
				isLoading1Clear = false;
				isLoading2Clear = false;
				isLoadingWinClear = false;
				isLoadingDeathClear = false;

			}
		}
		if (scene == win) {
			//音楽
			Novice::StopAudio(voiceHandle_Title);
			Novice::StopAudio(voiceHandle_Tutorial);
			Novice::StopAudio(voiceHandle_Selection);
			Novice::StopAudio(voiceHandle_Battle);
			Novice::StopAudio(voiceHandle_Lose);
			if (Novice::IsPlayingAudio(voiceHandle_Win) == 0 || voiceHandle_Win == -1) {
				voiceHandle_Win = Novice::PlayAudio(Sound_Win, true, 0.5f);
			}
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
				scene = TITLE;
				player.hp = player.maxHp;
				boss_1.hp = boss_1.maxHp;
				row = 0;
				column = 0;
				isHorizontal = true;
				isHit = false;
				frame = 0;
				isPlayerHit = false;
				framePlayeShake = 0;
				resetArr4x4(elementMap4x4);
				resetArr5x5(elementMap5x5);
				isLoading1Clear = false;
				isLoading2Clear = false;
				isLoadingWinClear = false;
				isLoadingDeathClear = false;
			}
		}
#pragma endregion
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
#pragma region stage TITLE
		if (scene == TITLE) {
			//Novice::DrawSprite(0, 0, Texture_Title, 1, 1, 0.0f, WHITE);
			//start animation
			Novice::DrawSprite(0, 0, startBkg, 1, 1, 0, WHITE);

			countStartAni++;
			if (countStartAni >= 32) {
				countStartAni = 0;
			}

			for (int i = 0; i < 4; i++) {
				if (countStartAni >= 0 + (i * 8) && countStartAni < 8 + (i * 8)) {
					Novice::DrawSpriteRect(0, 0, i * 1280, 0, 1280, 720, startButton, 0.25f, 1, 0, WHITE);
				}
			}

			countChip++;
			if (countChip >= 500) {
				countChip = 0;
			}
			if (countChip == 0) {
				chipX = -128;
			}

			if (countChip >= 5) {
				chipX += 5;
				Novice::DrawSpriteRect(int(chipX), int(chipY1), 0, 128, 128, 128, chip, 0.2f, 0.2f, 0, WHITE);
				Novice::DrawSpriteRect(int(chipX) - 130, int(chipY2), 128, 128, 128, 128, chip, 0.2f, 0.2f, 0, WHITE);
				Novice::DrawSpriteRect(int(chipX) - 260, int(chipY1), 2 * 128, 128, 128, 128, chip, 0.2f, 0.2f, 0, WHITE);
				Novice::DrawSpriteRect(int(chipX) - 390, int(chipY2), 3 * 128, 128, 128, 128, chip, 0.2f, 0.2f, 0, WHITE);
				Novice::DrawSpriteRect(int(chipX) - 520, int(chipY1), 4 * 128, 128, 128, 128, chip, 0.2f, 0.2f, 0, WHITE);
			}
		}
		if (scene == DOOR) {
			Novice::DrawSprite(0, 0, Texture_Door, 1, 1, 0.0f, WHITE);
		}
		if (scene == ZOOMDOOR) {
			Novice::DrawSprite(int(doorPosX), int(doorPosY), Texture_Door, doorExpansion, doorExpansion, 0.0f, WHITE);
		}
#pragma endregion
#pragma region stage 0
		if (scene == stage0) {
			//背景
			Novice::DrawSprite(0, 0, Texture_Background, 1, 1, 0.0f, WHITE);
			//Combat area
			Novice::DrawSprite(846, 50, Texture_BattleBG, 1, 1, 0.0f, WHITE);
			Novice::DrawBox(1102, 55, 128, 20, 0.0f, WHITE, kFillModeSolid);
			Novice::DrawBox(1102, 55, (int)(boss_1.hp * 128 / boss_1.maxHp), 20, 0.0f, RED, kFillModeSolid);
			Novice::DrawBox(846, 409, 128, 20, 0.0f, WHITE, kFillModeSolid);
			Novice::DrawBox(846, 409, (int)(player.hp * 128 / player.maxHp), 20, 0.0f, RED, kFillModeSolid);
			//enemy
			Novice::DrawSprite(846, 50, boss_1.texture, 1, 1, 0.0f, WHITE);
#pragma region 元素
			//色块矩阵
			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 4; x++) {
					if (tutorialMap4x4[y][x] == 1) {
						Novice::DrawSpriteRect(
							x * 128 + 40,// 40  矩阵的起始位置 x坐标
							y * 128 + 104,//104 矩阵的起始位置 y坐标
							0, 0,
							128, 128,
							Texture_Element,
							0.2f, 0.2f, 0.0f, WHITE// 0.2=每个元素的size128 / 总chip的size640
						);

					}
					if (tutorialMap4x4[y][x] == 2) {
						Novice::DrawSpriteRect(
							x * 128 + 40,
							y * 128 + 104,
							128, 0,
							128, 128,
							Texture_Element,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (tutorialMap4x4[y][x] == 3) {
						Novice::DrawSpriteRect(
							x * 128 + 40,
							y * 128 + 104,
							256, 0,
							128, 128,
							Texture_Element,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (tutorialMap4x4[y][x] == 4) {
						Novice::DrawSpriteRect(
							x * 128 + 40,
							y * 128 + 104,
							384, 0,
							128, 128,
							Texture_Element,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					//Novice::ScreenPrintf(x * 100 + 300, y * 15, ("[%d][%d]=%d"), y, x, elementMap4x4[y][x]);
				}
			}
#pragma endregion
			//center
			Novice::DrawSprite(128 + 40, 128 + 104, Texture_Center, 1, 1, 0.0f, WHITE);
			//Novice::ScreenPrintf(0, 0, ("row = %d"), row);
			//Novice::ScreenPrintf(0, 15, ("col = %d"), column);
			//Novice::ScreenPrintf(0, 30, ("step = %d"), stepNum);
#pragma region ボックス 移動 描画

			if (isHorizontal == true) {
				Novice::DrawSprite(
					40 - 14,
					(int)(row * 128 + 104),
					Texture_Select4x4[0],
					1, 1, 0.0f, WHITE
				);
			}
			if (isHorizontal == false) {
				Novice::DrawSprite(
					(int)(column * 128 + 40),
					104 - 14,
					Texture_Select4x4[1],
					1, 1, 0.0f, WHITE
				);
			}
#pragma endregion
#pragma region 戦闘

			//=======================================================
			//戦闘
			//=======================================================
			//目标矩阵
			for (int y = 0; y < 2; y++) {
				for (int x = 0; x < 2; x++) {
					if (targetMap0[y][x] == 1) {
						Novice::DrawSpriteRect(
							x * 64 + 840,
							y * 64 + 500,
							0, 0,
							128, 128,
							Texture_Element,
							0.1f, 0.1f, 0.0f, WHITE
						);

					}
					if (targetMap0[y][x] == 2) {
						Novice::DrawSpriteRect(
							x * 64 + 840,
							y * 64 + 500,
							128, 0,
							128, 128,
							Texture_Element,
							0.1f, 0.1f, 0.0f, WHITE
						);

					}
					if (targetMap0[y][x] == 3) {
						Novice::DrawSpriteRect(
							x * 64 + 840,
							y * 64 + 500,
							256, 0,
							128, 128,
							Texture_Element,
							0.1f, 0.1f, 0.0f, WHITE
						);
					}
					if (targetMap0[y][x] == 4) {
						Novice::DrawSpriteRect(
							x * 64 + 840,
							y * 64 + 500,
							384, 0,
							128, 128,
							Texture_Element,
							0.1f, 0.1f, 0.0f, WHITE
						);
					}
				}
			}
			//Novice::ScreenPrintf(800, 200, (" advatage = %d "), boss_1.advantage);
			//Novice::ScreenPrintf(800, 300, (" weakness = %d "), boss_1.weakness);
			if (boss_1.advantage == 1) {
				Novice::DrawSpriteRect(700, 200, 0, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_1.advantage == 2) {
				Novice::DrawSpriteRect(700, 200, 128, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_1.advantage == 3) {
				Novice::DrawSpriteRect(700, 200, 256, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_1.advantage == 4) {
				Novice::DrawSpriteRect(700, 200, 384, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}

			if (boss_1.weakness == 1) {
				Novice::DrawSpriteRect(700, 300, 0, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_1.weakness == 2) {
				Novice::DrawSpriteRect(700, 300, 128, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);

			}
			if (boss_1.weakness == 3) {
				Novice::DrawSpriteRect(700, 300, 256, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_1.weakness == 4) {
				Novice::DrawSpriteRect(700, 300, 384, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}



#pragma endregion
#pragma region Tutorial
			if (stepNum == 1 && isStep0Clear == true) {
				Novice::DrawSprite(750, 100, Texture_Tutorial[0], 1, 1, 0.0f, WHITE);
			}
			if (stepNum == 2 && isStep1Clear == true) {
				Novice::DrawSprite(700, 100, Texture_Tutorial[1], 1, 1, 0.0f, WHITE);
			}
			if (stepNum == 3 && isStep2Clear == true) {
				Novice::DrawSprite(750, 100, Texture_Tutorial[2], 1, 1, 0.0f, WHITE);
			}
			if (stepNum == 4 && isStep3Clear == true) {
				Novice::DrawSprite(700, 100, Texture_Tutorial[3], 1, 1, 0.0f, WHITE);
			}
			if (stepNum == 5 && isStep4Clear == true) {
				Novice::DrawSprite(750, 100, Texture_Tutorial[4], 1, 1, 0.0f, WHITE);
			}
			if (stepNum == 6 && isStep5Clear == true) {
				Novice::DrawSprite(700, 100, Texture_Tutorial[5], 1, 1, 0.0f, WHITE);
			}
			if (stepNum == 7 && isStep6Clear == true) {
				Novice::DrawSprite(750, 100, Texture_Tutorial[6], 1, 1, 0.0f, WHITE);
			}
			if (stepNum == 8 && isStep7Clear == true) {
				Novice::DrawBox(839, 499, 130, 130, 0.0f, BLACK, kFillModeWireFrame);
				Novice::DrawSprite(800, 200, Texture_Tutorial[7], 1, 1, 0.0f, WHITE);
			}
			if (stepNum == 9 && isStep8Clear == true) {
				Novice::DrawSprite(200, 200, Texture_Tutorial[8], 1, 1, 0.0f, WHITE);
			}
			if (stepNum == 10 && isStep9Clear == true) {
				switch (step10Step) {
					case 0:
						Novice::DrawSprite(200, 150, Texture_Tutorial[9], 1, 1, 0.0f, WHITE);
						break;
					case 1:
						Novice::DrawSprite(200, 150, Texture_Tutorial[10], 1, 1, 0.0f, WHITE);
						break;
					case 2:
						Novice::DrawSprite(200, 150, Texture_Tutorial[11], 1, 1, 0.0f, WHITE);
						break;
					case 3:
						Novice::DrawSprite(200, 150, Texture_Tutorial[12], 1, 1, 0.0f, WHITE);
						break;
				}
			}
			if (stepNum == 11 && isStep10Clear == true) {
				Novice::DrawSprite(300, 400, Texture_Tutorial[13], 1, 1, 0.0f, WHITE);
			}
			if (stepNum == 12 && isStep11Clear == true) {
				Novice::DrawSprite(300, 400, Texture_Tutorial[14], 1, 1, 0.0f, WHITE);
				for (int i = 0; i < 2; i++) {
					Novice::DrawSprite(576 + 64 * i, 50, Texture_Timer[eachTimerNumber[i]], 1, 1, 0.0f, WHITE);
				}
			}
			if (stepNum == 13 && isStep12Clear == true) {
				Novice::DrawSprite(300, 400, Texture_Tutorial[15], 1, 1, 0.0f, WHITE);
			}
			if (stepNum == 14 && isStep13Clear == true) {
				Novice::DrawSprite(384, 360, Texture_Tutorial[16], 1, 1, 0.0f, WHITE);
			}
#pragma endregion
		}
#pragma endregion
#pragma region stage selection
		if (scene == selection) {
			Novice::DrawSprite(0, 0, Texture_StageSelection, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(320, 480, Texture_StageNum1, 1, 1, 0.0f, WHITE);
			Novice::DrawSprite(860, 480, Texture_StageNum2, 1, 1, 0.0f, WHITE);
			if (stageSelection == nothing) {
				Novice::DrawSprite(200, 150, Texture_Boss1, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite(740, 150, Texture_Boss2, 1, 1, 0.0f, WHITE);

			}

			if (stageSelection == stage01) {
				Novice::DrawSprite((int)(200 - 38.4f), (int)(150 - 38.4f), Texture_Boss1, 1.2f, 1.2f, 0.0f, WHITE);
				Novice::DrawSprite(740, 150, Texture_Boss2, 1, 1, 0.0f, WHITE);
			}
			if (stageSelection == stage02) {
				Novice::DrawSprite(200, 150, Texture_Boss1, 1, 1, 0.0f, WHITE);
				Novice::DrawSprite((int)(740 - 38.4f), (int)(150 - 38.4f), Texture_Boss2, 1.2f, 1.2f, 0.0f, WHITE);

			}
		}
#pragma endregion
#pragma region loading 描画

#pragma region loading 1
		if (scene == loading1) {
			Novice::DrawSprite(0, 0, Texture_Background, 1, 1, 0.0f, WHITE);
			for (int y = 0; y < 6; y++) {
				for (int x = 0; x < 10; x++) {
					if (loading1Map[y][x] == 1) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							0, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loading1Map[y][x] == 2) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							128, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loading1Map[y][x] == 3) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							256, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loading1Map[y][x] == 4) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							384, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loading1Map[y][x] == 5) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							512, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
				}
			}
		}
#pragma endregion
#pragma region loading 2

		if (scene == loading2) {
			Novice::DrawSprite(0, 0, Texture_Background, 1, 1, 0.0f, WHITE);
			for (int y = 0; y < 6; y++) {
				for (int x = 0; x < 10; x++) {
					if (loading2Map[y][x] == 1) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							0, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loading2Map[y][x] == 2) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							128, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loading2Map[y][x] == 3) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							256, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loading2Map[y][x] == 4) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							384, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loading2Map[y][x] == 5) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							512, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
				}
			}
		}
#pragma endregion
#pragma region loading win
		if (scene == loadingWin) {
			Novice::DrawSprite(0, 0, Texture_Background, 1, 1, 0.0f, WHITE);
			for (int y = 0; y < 6; y++) {
				for (int x = 0; x < 10; x++) {
					if (loadingWinMap[y][x] == 1) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							0, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loadingWinMap[y][x] == 2) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							128, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loadingWinMap[y][x] == 3) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							256, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loadingWinMap[y][x] == 4) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							384, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loadingWinMap[y][x] == 5) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							512, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
				}
			}
		}
#pragma endregion
#pragma region loading death
		if (scene == loadingDeath) {
			Novice::DrawSprite(0, 0, Texture_Background, 1, 1, 0.0f, WHITE);
			for (int y = 0; y < 6; y++) {
				for (int x = 0; x < 10; x++) {
					if (loadingDeathMap[y][x] == 1) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							0, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loadingDeathMap[y][x] == 2) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							128, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loadingDeathMap[y][x] == 3) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							256, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loadingDeathMap[y][x] == 4) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							384, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
					if (loadingDeathMap[y][x] == 5) {
						Novice::DrawSpriteRect(
							x * 128, y * 128,
							512, 0,
							128, 128,
							chip,
							0.2f, 0.2f, 0.0f, WHITE
						);
					}
				}
			}
		}
#pragma endregion

#pragma endregion
#pragma region stage 1 描画
		if (scene == stage1) {
			//背景
			Novice::DrawSprite(0, 0, Texture_Background, 1, 1, 0.0f, WHITE);
			//timer
			for (int i = 0; i < 2; i++) {
				Novice::DrawSprite(576 + 64 * i, 50, Texture_Timer[eachTimerNumber[i]], 1, 1, 0.0f, WHITE);
			}
			//Combat area
			Novice::DrawSprite(846, 50, Texture_BattleBG, 1, 1, 0.0f, WHITE);
			Novice::DrawBox(1102, 55, 128, 20, 0.0f, WHITE, kFillModeSolid);
			Novice::DrawBox(1102, 55, (int)(boss_1.hp * 128 / boss_1.maxHp), 20, 0.0f, RED, kFillModeSolid);
			Novice::DrawBox(846, 409, 128, 20, 0.0f, WHITE, kFillModeSolid);
			Novice::DrawBox(846, 409, (int)(player.hp * 128 / player.maxHp), 20, 0.0f, RED, kFillModeSolid);
			//enemy
			if (frame > 0) {
				Novice::DrawSprite((int)(boss_1.pos.x + randX), (int)(boss_1.pos.y + randY), boss_1.texture_hit, 1, 1, 0.0f, WHITE);
			}
			else {
				//Novice::DrawSprite((int)(boss_1.pos.x + randX), (int)(boss_1.pos.y + randY), boss_1.texture, 1, 1, 0.0f, WHITE);
				Novice::DrawSpriteRect(
					(int)(boss_1.pos.x + randX), (int)(boss_1.pos.y + randY),                       // 描画するスプライトの左上座標   这个图片显示的位置
					slimeDraw, 0,                            // 画像上の描画したい範囲左上座標 加载画像上的想截取显示的起始位置
					384, 384,                     // 画像上の描画したい横幅、縦幅   想截取显示的范围
					boss_1.texture,                            // テクスチャハンドル
					// 横長の画像を正方形で描画するためにアスペクト比を1:1にする
					//(float)height / (float)width)这个值*2就是拉长2倍，/2就是缩小2倍
					0.25f, 1,  // 描画するスプライトの倍率
					0,                                  // 描画するスプライトの回転角
					WHITE                               // 色
				);
			}

#pragma region 元素 描画
			//元素
			if (framePlayeShake > 0) {
				for (int y = 0; y < 4; y++) {
					for (int x = 0; x < 4; x++) {
						if (elementMap4x4[y][x] == 1) {
							Novice::DrawSpriteRect(
								(int)(x * 128 + 40 + randPlayeShakeX),// 40  矩阵的起始位置 x坐标
								(int)(y * 128 + 104 + randPlayeShakeY),//104 矩阵的起始位置 y坐标
								0, 0,
								128, 128,
								Texture_Element,
								0.2f, 0.2f, 0.0f, WHITE// 0.2=每个元素的size128 / 总chip的size640
							);

						}
						if (elementMap4x4[y][x] == 2) {
							Novice::DrawSpriteRect(
								(int)(x * 128 + 40 + randPlayeShakeX),// 40  矩阵的起始位置 x坐标
								(int)(y * 128 + 104 + randPlayeShakeY),//104 矩阵的起始位置 y坐标
								128, 0,
								128, 128,
								Texture_Element,
								0.2f, 0.2f, 0.0f, WHITE
							);
						}
						if (elementMap4x4[y][x] == 3) {
							Novice::DrawSpriteRect(
								(int)(x * 128 + 40 + randPlayeShakeX),// 40  矩阵的起始位置 x坐标
								(int)(y * 128 + 104 + randPlayeShakeY),//104 矩阵的起始位置 y坐标
								256, 0,
								128, 128,
								Texture_Element,
								0.2f, 0.2f, 0.0f, WHITE
							);
						}
						if (elementMap4x4[y][x] == 4) {
							Novice::DrawSpriteRect(
								(int)(x * 128 + 40 + randPlayeShakeX),// 40  矩阵的起始位置 x坐标
								(int)(y * 128 + 104 + randPlayeShakeY),//104 矩阵的起始位置 y坐标
								384, 0,
								128, 128,
								Texture_Element,
								0.2f, 0.2f, 0.0f, WHITE
							);
						}
						//Novice::ScreenPrintf(x * 100 + 300, y * 15, ("[%d][%d]=%d"), y, x, elementMap4x4[y][x]);
					}
				}
			}
			else {
				for (int y = 0; y < 4; y++) {
					for (int x = 0; x < 4; x++) {
						if (elementMap4x4[y][x] == 1) {
							Novice::DrawSpriteRect(
								x * 128 + 40,// 40  矩阵的起始位置 x坐标
								y * 128 + 104,//104 矩阵的起始位置 y坐标
								0, 0,
								128, 128,
								Texture_Element,
								0.2f, 0.2f, 0.0f, WHITE// 0.2=每个元素的size128 / 总chip的size640
							);

						}
						if (elementMap4x4[y][x] == 2) {
							Novice::DrawSpriteRect(
								x * 128 + 40,
								y * 128 + 104,
								128, 0,
								128, 128,
								Texture_Element,
								0.2f, 0.2f, 0.0f, WHITE
							);
						}
						if (elementMap4x4[y][x] == 3) {
							Novice::DrawSpriteRect(
								x * 128 + 40,
								y * 128 + 104,
								256, 0,
								128, 128,
								Texture_Element,
								0.2f, 0.2f, 0.0f, WHITE
							);
						}
						if (elementMap4x4[y][x] == 4) {
							Novice::DrawSpriteRect(
								x * 128 + 40,
								y * 128 + 104,
								384, 0,
								128, 128,
								Texture_Element,
								0.2f, 0.2f, 0.0f, WHITE
							);
						}
						//Novice::ScreenPrintf(x * 100 + 300, y * 15, ("[%d][%d]=%d"), y, x, elementMap4x4[y][x]);
					}
				}
			}
#pragma endregion
			//center
			Novice::DrawSprite(128 + 40, 128 + 104, Texture_Center, 1, 1, 0.0f, WHITE);
			//Novice::ScreenPrintf(0, 0, ("row = %d"), row);
			//Novice::ScreenPrintf(0, 15, ("col = %d"), column);
#pragma region combo 描画
			//combo
			switch (combo) {
				case 0:
					break;
				case 1:
					break;
				case 2:
					Novice::DrawSprite(1000, 550, Texture_Combo_2, 1, 1, 0.0f, WHITE);
					break;
				case 3:
					Novice::DrawSprite(1000, 550, Texture_Combo_3, 1, 1, 0.0f, WHITE);
					break;
				case 4:
					Novice::DrawSprite(1000, 550, Texture_Combo_4, 1, 1, 0.0f, WHITE);
					break;
				case 5:
					Novice::DrawSprite(1000, 550, Texture_Combo_5, 1, 1, 0.0f, WHITE);
					break;
				case 6:
					Novice::DrawSprite(1000, 550, Texture_Combo_6, 1, 1, 0.0f, WHITE);
					break;
				case 7:
					Novice::DrawSprite(1000, 550, Texture_Combo_7, 1, 1, 0.0f, WHITE);
					break;
				case 8:
					Novice::DrawSprite(1000, 550, Texture_Combo_8, 1, 1, 0.0f, WHITE);
					break;
				case 9:
					Novice::DrawSprite(1000, 550, Texture_Combo_9, 1, 1, 0.0f, WHITE);
					break;
				case 10:
					Novice::DrawSprite(1000, 550, Texture_Combo_10, 1, 1, 0.0f, WHITE);
					break;
			}
#pragma endregion
#pragma region ボックス 移動 描画

			if (isHorizontal == true) {
				Novice::DrawSprite(
					40 - 14,
					(int)(row * 128 + 104),
					Texture_Select4x4[0],
					1, 1, 0.0f, WHITE
				);
			}
			if (isHorizontal == false) {
				Novice::DrawSprite(
					(int)(column * 128 + 40),
					104 - 14,
					Texture_Select4x4[1],
					1, 1, 0.0f, WHITE
				);
			}
#pragma endregion
#pragma region 戦闘 描画

			//=======================================================
			//戦闘
			//=======================================================
			//目标矩阵
			for (int y = 0; y < 2; y++) {
				for (int x = 0; x < 2; x++) {
					if (targetMap1[y][x] == 1) {
						Novice::DrawSpriteRect(
							x * 64 + 840,
							y * 64 + 500,
							0, 0,
							128, 128,
							Texture_Element,
							0.1f, 0.1f, 0.0f, WHITE
						);

					}
					if (targetMap1[y][x] == 2) {
						Novice::DrawSpriteRect(
							x * 64 + 840,
							y * 64 + 500,
							128, 0,
							128, 128,
							Texture_Element,
							0.1f, 0.1f, 0.0f, WHITE
						);

					}
					if (targetMap1[y][x] == 3) {
						Novice::DrawSpriteRect(
							x * 64 + 840,
							y * 64 + 500,
							256, 0,
							128, 128,
							Texture_Element,
							0.1f, 0.1f, 0.0f, WHITE
						);
					}
					if (targetMap1[y][x] == 4) {
						Novice::DrawSpriteRect(
							x * 64 + 840,
							y * 64 + 500,
							384, 0,
							128, 128,
							Texture_Element,
							0.1f, 0.1f, 0.0f, WHITE
						);
					}
				}
			}
			//Novice::ScreenPrintf(800, 200, (" advatage = %d "), boss_1.advantage);
			//Novice::ScreenPrintf(800, 300, (" weakness = %d "), boss_1.weakness);
			if (boss_1.advantage == 1) {
				Novice::DrawSpriteRect(700, 200, 0, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_1.advantage == 2) {
				Novice::DrawSpriteRect(700, 200, 128, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_1.advantage == 3) {
				Novice::DrawSpriteRect(700, 200, 256, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_1.advantage == 4) {
				Novice::DrawSpriteRect(700, 200, 384, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}

			if (boss_1.weakness == 1) {
				Novice::DrawSpriteRect(700, 300, 0, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_1.weakness == 2) {
				Novice::DrawSpriteRect(700, 300, 128, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_1.weakness == 3) {
				Novice::DrawSpriteRect(700, 300, 256, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_1.weakness == 4) {
				Novice::DrawSpriteRect(700, 300, 384, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}



#pragma endregion
		}
#pragma endregion
#pragma region stage 2 描画
		if (scene == stage2) {
			//背景
			Novice::DrawSprite(0, 0, Texture_Background, 1, 1, 0.0f, WHITE);
			//timer
			for (int i = 0; i < 2; i++) {
				Novice::DrawSprite(576 + 64 * i, 50, Texture_Timer[eachTimerNumber[i]], 1, 1, 0.0f, WHITE);
			}
			//Combat area
			Novice::DrawSprite(846, 50, Texture_BattleBG, 1, 1, 0.0f, WHITE);
			Novice::DrawBox(1102, 55, 128, 20, 0.0f, WHITE, kFillModeSolid);
			Novice::DrawBox(1102, 55, (int)(boss_2.hp * 128 / boss_2.maxHp), 20, 0.0f, RED, kFillModeSolid);
			Novice::DrawBox(846, 409, 128, 20, 0.0f, WHITE, kFillModeSolid);
			Novice::DrawBox(846, 409, (int)(player.hp * 128 / player.maxHp), 20, 0.0f, RED, kFillModeSolid);
			//enemy
			if (frame > 0) {
				Novice::DrawSprite((int)(boss_2.pos.x + randX), (int)(boss_2.pos.y + randY), boss_2.texture_hit, 1, 1, 0.0f, WHITE);
			}
			else {
				//Novice::DrawSprite((int)(boss_2.pos.x + randX), (int)(boss_2.pos.y + randY), boss_2.texture, 1, 1, 0.0f, WHITE);
				Novice::DrawSpriteRect(
					(int)(boss_2.pos.x + randX), (int)(boss_2.pos.y + randY),                       // 描画するスプライトの左上座標   这个图片显示的位置
					ghostDraw, 0,                            // 画像上の描画したい範囲左上座標 加载画像上的想截取显示的起始位置
					384, 384,                     // 画像上の描画したい横幅、縦幅   想截取显示的范围
					boss_2.texture,                            // テクスチャハンドル
					// 横長の画像を正方形で描画するためにアスペクト比を1:1にする
					//(float)height / (float)width)这个值*2就是拉长2倍，/2就是缩小2倍
					0.25f, 1,  // 描画するスプライトの倍率
					0,                                  // 描画するスプライトの回転角
					WHITE                               // 色
				);
			}
#pragma region 元素 描画
			//元素
			if (framePlayeShake > 0) {
				for (int y = 0; y < 5; y++) {
					for (int x = 0; x < 5; x++) {
						if (elementMap5x5[y][x] == 1) {
							Novice::DrawSpriteRect(
								(int)(x * 102.4f + 40 + randPlayeShakeX),//102.4=128*(512/640)
								(int)(y * 102.4f + 104 + randPlayeShakeY),
								0, 0,
								128, 128,
								Texture_Element,
								0.16f, 0.16f, 0.0f, WHITE//0.16=0.2/0.8=(128/640)*(512/640)
							);
						}
						if (elementMap5x5[y][x] == 2) {
							Novice::DrawSpriteRect(
								(int)(x * 102.4f + 40 + randPlayeShakeX),
								(int)(y * 102.4f + 104 + randPlayeShakeY),
								128, 0,
								128, 128,
								Texture_Element,
								0.16f, 0.16f, 0.0f, WHITE
							);
						}
						if (elementMap5x5[y][x] == 3) {
							Novice::DrawSpriteRect(
								(int)(x * 102.4f + 40 + randPlayeShakeX),
								(int)(y * 102.4f + 104 + randPlayeShakeY),
								256, 0,
								128, 128,
								Texture_Element,
								0.16f, 0.16f, 0.0f, WHITE
							);
						}
						if (elementMap5x5[y][x] == 4) {
							Novice::DrawSpriteRect(
								(int)(x * 102.4f + 40 + randPlayeShakeX),
								(int)(y * 102.4f + 104 + randPlayeShakeY),
								384, 0,
								128, 128,
								Texture_Element,
								0.16f, 0.16f, 0.0f, WHITE
							);
						}
						if (elementMap5x5[y][x] == 5) {
							Novice::DrawSpriteRect(
								(int)(x * 102.4f + 40 + randPlayeShakeX),
								(int)(y * 102.4f + 104 + randPlayeShakeY),
								512, 0,
								128, 128,
								Texture_Element,
								0.16f, 0.16f, 0.0f, WHITE
							);
						}
						//Novice::ScreenPrintf(x * 100 + 300, y * 15, ("[%d][%d]=%d"), y, x, elementMap5x5[y][x]);
					}
				}
			}
			else {
				for (int y = 0; y < 5; y++) {
					for (int x = 0; x < 5; x++) {
						if (elementMap5x5[y][x] == 1) {
							Novice::DrawSpriteRect(
								(int)(x * 102.4f + 40),//102.4=128*(512/640)
								(int)(y * 102.4f + 104),
								0, 0,
								128, 128,
								Texture_Element,
								0.16f, 0.16f, 0.0f, WHITE//0.16=0.2/0.8=(128/640)*(512/640)
							);
						}
						if (elementMap5x5[y][x] == 2) {
							Novice::DrawSpriteRect(
								(int)(x * 102.4f + 40),
								(int)(y * 102.4f + 104),
								128, 0,
								128, 128,
								Texture_Element,
								0.16f, 0.16f, 0.0f, WHITE
							);
						}
						if (elementMap5x5[y][x] == 3) {
							Novice::DrawSpriteRect(
								(int)(x * 102.4f + 40),
								(int)(y * 102.4f + 104),
								256, 0,
								128, 128,
								Texture_Element,
								0.16f, 0.16f, 0.0f, WHITE
							);
						}
						if (elementMap5x5[y][x] == 4) {
							Novice::DrawSpriteRect(
								(int)(x * 102.4f + 40),
								(int)(y * 102.4f + 104),
								384, 0,
								128, 128,
								Texture_Element,
								0.16f, 0.16f, 0.0f, WHITE
							);
						}
						if (elementMap5x5[y][x] == 5) {
							Novice::DrawSpriteRect(
								(int)(x * 102.4f + 40),
								(int)(y * 102.4f + 104),
								512, 0,
								128, 128,
								Texture_Element,
								0.16f, 0.16f, 0.0f, WHITE
							);
						}
						//Novice::ScreenPrintf(x * 100 + 300, y * 15, ("[%d][%d]=%d"), y, x, elementMap5x5[y][x]);
					}
				}
			}

#pragma endregion
			//center
			Novice::DrawSprite((int)(102.4f + 40), (int)(102.4f + 104), Texture_Center, 1.2f, 1.2f, 0.0f, WHITE);
			//Novice::ScreenPrintf(0, 0, ("row = %d"), row);
			//Novice::ScreenPrintf(0, 15, ("col = %d"), column);
#pragma region combo 描画
			//combo
			switch (combo) {
				case 0:
					break;
				case 1:
					break;
				case 2:
					Novice::DrawSprite(1000, 550, Texture_Combo_2, 1, 1, 0.0f, WHITE);
					break;
				case 3:
					Novice::DrawSprite(1000, 550, Texture_Combo_3, 1, 1, 0.0f, WHITE);
					break;
				case 4:
					Novice::DrawSprite(1000, 550, Texture_Combo_4, 1, 1, 0.0f, WHITE);
					break;
				case 5:
					Novice::DrawSprite(1000, 550, Texture_Combo_5, 1, 1, 0.0f, WHITE);
					break;
				case 6:
					Novice::DrawSprite(1000, 550, Texture_Combo_6, 1, 1, 0.0f, WHITE);
					break;
				case 7:
					Novice::DrawSprite(1000, 550, Texture_Combo_7, 1, 1, 0.0f, WHITE);
					break;
				case 8:
					Novice::DrawSprite(1000, 550, Texture_Combo_8, 1, 1, 0.0f, WHITE);
					break;
				case 9:
					Novice::DrawSprite(1000, 550, Texture_Combo_9, 1, 1, 0.0f, WHITE);
					break;
				case 10:
					Novice::DrawSprite(1000, 550, Texture_Combo_10, 1, 1, 0.0f, WHITE);
					break;
			}
#pragma endregion
#pragma region ボックス 移動 描画
			if (isHorizontal == true) {
				Novice::DrawSprite(
					40 - 14,// 14是比640横幅两边各多14像素的三角符号
					(int)(row * 128 * 0.8 + 104),
					Texture_Select5x5[0],
					0.8f, 0.8f, 0.0f, WHITE //0.8= 512/640
				);
			}
			if (isHorizontal == false) {
				Novice::DrawSprite(
					(int)(column * 128 * 0.8 + 40),
					104 - 14,
					Texture_Select5x5[1],
					0.8f, 0.8f, 0.0f, WHITE
				);
			}
#pragma endregion
#pragma region 戦闘 描画

			//=======================================================
			//戦闘
			//=======================================================
			//目标矩阵
			for (int y = 0; y < 3; y++) {
				for (int x = 0; x < 3; x++) {
					if (targetMap2[y][x] == 1) {
						Novice::DrawSpriteRect(
							(int)(x * 64 * 2 / 3 + 840),// 2/3 = 原来2个方块size 128 / 现在3个方块size 196
							(int)(y * 64 * 2 / 3 + 500),
							0, 0,
							128, 128,
							Texture_Element,
							0.1f * 2 / 3, 0.1f * 2 / 3, 0.0f, WHITE
						);
					}
					if (targetMap2[y][x] == 2) {
						Novice::DrawSpriteRect(
							(int)(x * 64 * 2 / 3 + 840),
							(int)(y * 64 * 2 / 3 + 500),
							128, 0,
							128, 128,
							Texture_Element,
							0.1f * 2 / 3, 0.1f * 2 / 3, 0.0f, WHITE
						);
					}
					if (targetMap2[y][x] == 3) {
						Novice::DrawSpriteRect(
							(int)(x * 64 * 2 / 3 + 840),
							(int)(y * 64 * 2 / 3 + 500),
							256, 0,
							128, 128,
							Texture_Element,
							0.1f * 2 / 3, 0.1f * 2 / 3, 0.0f, WHITE
						);
					}
					if (targetMap2[y][x] == 4) {
						Novice::DrawSpriteRect(
							(int)(x * 64 * 2 / 3 + 840),
							(int)(y * 64 * 2 / 3 + 500),
							384, 0,
							128, 128,
							Texture_Element,
							0.1f * 2 / 3, 0.1f * 2 / 3, 0.0f, WHITE
						);
					}
					if (targetMap2[y][x] == 5) {
						Novice::DrawSpriteRect(
							(int)(x * 64 * 2 / 3 + 840),
							(int)(y * 64 * 2 / 3 + 500),
							512, 0,
							128, 128,
							Texture_Element,
							0.1f * 2 / 3, 0.1f * 2 / 3, 0.0f, WHITE
						);
					}
				}
			}
			//Novice::ScreenPrintf(800, 200, (" advatage = %d "), boss_2.advantage);
			//Novice::ScreenPrintf(800, 300, (" weakness = %d "), boss_2.weakness);
			if (boss_2.advantage == 1) {
				Novice::DrawSpriteRect(700, 200, 0, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_2.advantage == 2) {
				Novice::DrawSpriteRect(700, 200, 128, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_2.advantage == 3) {
				Novice::DrawSpriteRect(700, 200, 256, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_2.advantage == 4) {
				Novice::DrawSpriteRect(700, 200, 384, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}

			if (boss_2.weakness == 1) {
				Novice::DrawSpriteRect(700, 300, 0, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_2.weakness == 2) {
				Novice::DrawSpriteRect(700, 300, 128, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);

			}
			if (boss_2.weakness == 3) {
				Novice::DrawSpriteRect(700, 300, 256, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}
			if (boss_2.weakness == 4) {
				Novice::DrawSpriteRect(700, 300, 384, 0, 128, 128, Texture_Element, 0.1f, 0.1f, 0.0f, WHITE);
			}


#pragma endregion
		}
#pragma endregion 
#pragma region 勝敗 描画
		if (scene == death) {
			Novice::DrawSprite(0, 0, Texture_Lose, 1, 1, 0.0f, WHITE);
		}
		if (scene == win) {
			Novice::DrawSprite(0, 0, Texture_Win, 1, 1, 0.0f, WHITE);
		}
#pragma endregion
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
