#include <raylib.h>
#include <raymath.h>
#include <math.h>

#define TEX_SIZE 8
#define SOUND_SIZE 8
#define SFXALIAS_SIZE 8
#define FONT_QUALITY 128

typedef struct SafeTexture SafeTexture;
typedef struct SafeSound SafeSound;
typedef struct StateData StateData;
typedef enum State State;

enum State {
	STATE_INTRO,
	STATE_DBINTRO
};
struct SafeTexture {
	Texture2D tex;
	bool init;
};
struct SafeSound {
	Sound sound;
	bool init;
};
struct StateData {
	State state;
	int frame;
	Color bgColor;
	Font font;
	Font auxFont;
	SafeTexture textures[TEX_SIZE]; // Todas las texturas que se utilizan durante el tiempo de ejecución se mantienen aquí
	Music music;
	SafeSound sounds[10]; // Todas los sonidos que se utilizan durante el tiempo de ejecución se mantienen aquí
	SafeSound sfxAlias[10]; // Un array de sonidos para copiar referencias de "sounds", así se pueden tener efectos de sonido en paralelo
	int sfxPosition; // Posición para localizar un sfxAlias "libre"
};

void UpdateState(StateData *state);
void DrawState(StateData *state);
void SetState(StateData *state, State newState); 
void PlaySecSound(StateData *state, int id);
float HeavisideEasing(float value, float step);

int main() {
	//-------------------------------------------------------------
	// Cámara y efecto de Píxeles Perfectos
	//-------------------------------------------------------------
	
	const int virtualScreenWidth = 320;
	const int virtualScreenHeight = 180;
	const int screenWidth = 960;
	const int screenHeight = 540;
	InitWindow(screenWidth, screenHeight, "Base de Datos - Intro");
	const float virtualRatio = (float)screenWidth/(float)virtualScreenWidth;
	Camera2D worldSpaceCamera = { {0, 0}, {0, 0}, 0.0f, 1.0f };
	Camera2D screenSpaceCamera = { {0, 0}, {0, 0}, 0.0f, 1.0f };
	RenderTexture2D target = LoadRenderTexture(virtualScreenWidth, virtualScreenHeight);
	Rectangle sourceRec = { 0.0f, 0.0f, (float) target.texture.width, - (float) target.texture.height };
	Rectangle destRec = { -virtualRatio, -virtualRatio , screenWidth + (virtualRatio * 2), screenHeight + (virtualRatio * 2) };
	Vector2 origin = { 0.0f, 0.0f };
	SetTargetFPS(60);// INFO: Set our game to run at 60 frames-per-second

	//-------------------------------------------------------------
	// Game Inputs and State
	//-------------------------------------------------------------
	
	StateData state; // Contains the current state of the game
	int i;

	//-------------------------------------------------------------
	// Audio and Sound
	//-------------------------------------------------------------
	
	InitAudioDevice();

	SetState(&state, STATE_INTRO);

	while (!WindowShouldClose()) {

		UpdateState(&state);

		//-------------------------------------------------------------
		// INFO: Texture: In this texture mode I create an smaller version of the game which is later rescaled in the draw mode
		//-------------------------------------------------------------

		BeginTextureMode(target);
			ClearBackground(state.bgColor);
			BeginMode2D(worldSpaceCamera);
				DrawState(&state);
			EndMode2D();
		EndTextureMode();

		//-------------------------------------------------------------
		// INFO: Draw: Take the texture in lower resolution and rescale it to a bigger res, all this while preserving pixel perfect
		//-------------------------------------------------------------

		BeginDrawing();
			ClearBackground(RED);
			BeginMode2D(screenSpaceCamera);
				DrawTexturePro(target.texture, sourceRec, destRec, origin, 0.0f, WHITE);
			EndMode2D();
			DrawFPS(10, 10);
		EndDrawing();
	}

	StopMusicStream(state.music);
	UnloadRenderTexture(target);
	UnloadMusicStream(state.music); // Unload music stream buffers from RAM
	UnloadFont(state.font);
	UnloadFont(state.auxFont);

	for (i = 0; i < TEX_SIZE; i++) {
		if (state.textures[i].init) {
			UnloadTexture(state.textures[i].tex);
			state.textures[i].init = false;
		}
	}
	for (i = 0; i < SFXALIAS_SIZE; i++) {
		if (state.sfxAlias[i].init) {
			UnloadSoundAlias(state.sfxAlias[i].sound);
			state.sfxAlias[i].init = false;
		}
	}
	for (i = 0; i < SOUND_SIZE; i++) {
		if (state.sounds[i].init) {
			UnloadSound(state.sounds[i].sound);
			state.sounds[i].init = false;
		}
	}

	CloseAudioDevice(); // Close audio device (music streaming is automatically stopped)
	CloseWindow(); // Close window and OpenGL context

	return 0;
}

void PlaySecSound(StateData *state, int id) {
	id = id % 10;
	if (state->sfxAlias[state->sfxPosition].init)
		UnloadSoundAlias(state->sfxAlias[state->sfxPosition].sound);
	state->sfxAlias[state->sfxPosition].sound = LoadSoundAlias(state->sounds[id].sound);
	state->sfxAlias[state->sfxPosition].init = true;
	PlaySound(state->sfxAlias[state->sfxPosition].sound);
	state->sfxPosition = (state->sfxPosition + 1) % 10;
}
void UpdateState(StateData *state) {
	state->frame++;
	switch (state->state) {
		case STATE_INTRO:
			if (state->frame > 220) {
				state->bgColor = (Color) { Clamp(state->bgColor.r - 5, 5, 255),
							   Clamp(state->bgColor.g - 5, 0, 255),
							   Clamp(state->bgColor.b - 5, 0, 255),
							   255};
			}
			if (state->frame == 320) SetState(state, STATE_DBINTRO);
			break;
		case STATE_DBINTRO:
			break;
		default: break;
	}
}
void DrawState(StateData *state) {
	switch (state->state) {
		case STATE_INTRO:
			if (state->frame < 155) {
				DrawTexture(state->textures[2].tex, 0, 0, WHITE);
				DrawTextPro(state->font, "elf", (Vector2) { 104, 140 }, (Vector2) { 0, 0 }, 0, 18, 1, (Color) { 5, 0, 0, 255});
				DrawTextPro(state->font, "elf", (Vector2) { 106, 140 }, (Vector2) { 0, 0 }, 0, 18, 1, (Color) { 5, 0, 0, 255});
				DrawTextPro(state->font, "elf", (Vector2) { 105, 139 }, (Vector2) { 0, 0 }, 0, 18, 1, (Color) { 5, 0, 0, 255});
				DrawTextPro(state->font, "elf", (Vector2) { 105, 141 }, (Vector2) { 0, 0 }, 0, 18, 1, (Color) { 5, 0, 0, 255});
				DrawTextPro(state->font, "elf", (Vector2) { 105, 140 }, (Vector2) { 0, 0 }, 0, 18, 1, (Color) { 255, 245, 245, 255});
				DrawTexture(state->textures[0].tex, Lerp(210, 0, HeavisideEasing((float) (-320 + state->frame * 4) / 120, 30)), 0, WHITE);
				DrawTexture(state->textures[1].tex, Lerp(0, -210, HeavisideEasing((float) (-120 + state->frame * 4) / 120, 30)), 0, WHITE);
			}
			else if (state->frame >= 155) {
				DrawTexture(state->textures[3].tex, 1, 0, (Color) { 255, 255, 255, Clamp(255 + (220 - state->frame) * 5, 0, 255 ) });
				DrawTextPro(state->font, TextSubtext("pectrum", 0, Clamp((-155 + state->frame) / 5, 0, 7)),
					    (Vector2) { 105, 140 }, (Vector2) { 0, 0 }, 0, 18, 1, (Color) { 5, 0, 0, Clamp(255 + (220 - state->frame) * 5, 0, 255)});
			}
			// Лорена делгадо, Данйел Галвез, Павло Сантандер, Христофер Казерес
			// Vigilancia tecnológica -> Adquisición de competencias -> Desafíos reales ->
			// Asociación estratética -> Conformación del equipo -> Modos de financiamiento ->
			// Gestión de proyecтo -> Entrega de resultados -> Transferencia de conocimiento
			//
			// Пабло Оливарес, Дйего Монсалвес, Дйего Миранда
			// SCRUM dentro del entorno minero.
			// Optimización de SCRUM mediante el uso de LLMs como SCRUM Master
			//
			// Йоел Линарес
			//
			// Нагур Мелендез
			// Opciones reales y su aplicación
			//
			// Игнацё Мелендез Ескобедо
			// Primed to Perform - Neel Doshi
			// Del laboratorio al mercado - Alvaro Ossa
			//
			// Гиджермо Мачука
			// Мйел Адултерада
			break;
		case STATE_DBINTRO:
			DrawTextPro(state->auxFont, TextSubtext("Capítulo 1 - Introducción", 0, Clamp(state->frame / 5, 0, 30)),
				    (Vector2) { 8, 160 }, (Vector2) { 0, 0 },
				    0, 18, 1, (Color) { 255, 245, 245, Clamp((360 - state->frame) * 5, 0, 255 ) });
			DrawRectangle(130, 65, 60, 70 * HeavisideEasing((float) (-240 + state->frame) / 80, 20), (Color) { 255, 245, 245, 255 });
			DrawEllipse(160, 65 + 3 * HeavisideEasing((float) (-180 + state->frame) / 80, 20), 29.5f,
					15 * HeavisideEasing((float) (-240 + state->frame) / 80, 20), (Color) { 5, 0, 0, 255 });
			DrawEllipse(160, 65, 30, 15 * HeavisideEasing((float) (-120 + state->frame) / 80, 20), (Color) { 255, 245, 245, 255 });
			DrawEllipse(160, 65 + 70 * HeavisideEasing((float) (-240 + state->frame) / 80, 20), 30,
					15 * HeavisideEasing((float) (-240 + state->frame) / 80, 20), (Color) { 255, 245, 245, 255 });
			break;
		default: break;
	}
}
void SetState(StateData *state, State newState) {
	int codepoints[210] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 1041, 1042, 1043, 1044, 1045, 1046, 1047, 1048, 1049, 160, 1050, 1051, 1052, 176, 1053, 1054, 1055, 191, 1025, 193, 1056, 1057, 201, 1058, 205, 209, 1059, 211, 1060, 215, 218, 1061, 1062, 225, 1063, 233, 1064, 237, 1065, 241, 243, 1066, 247, 1067, 250, 1068, 1069, 1070, 1071, 1072, 1040, 1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088, 1089, 1090, 1091, 1092, 1093, 1094, 1095, 1096, 1097, 1098, 1099, 1100, 1101, 1102, 1103, 1105};
	int i;
	state->frame = 0;
	state->state = newState;
	for (i = 0; i < TEX_SIZE; i++) {
		if (state->textures[i].init) {
			UnloadTexture(state->textures[i].tex);
			state->textures[i].init = false;
		}
	}
	switch (state->state) {
		case STATE_INTRO:
			int i;
			state->font = LoadFontEx("./res/fonts/UpheavalPro.ttf", FONT_QUALITY, codepoints, 210);
			state->auxFont = LoadFontEx("./res/fonts/Pixel-UniCode.ttf", FONT_QUALITY, codepoints, 210);
			for (i = 0; i < TEX_SIZE; i++) state->textures[i].init = false;
			for (i = 0; i < SOUND_SIZE; i++) state->sounds[i].init = false;
			for (i = 0; i < SFXALIAS_SIZE; i++) state->sfxAlias[i].init = false;

			state->bgColor = (Color) { 255, 245, 245, 255 };

			state->music = LoadMusicStream("./res/sfx/danseMacabre.mp3");
			state->music.looping = true;
			state->textures[0].tex = LoadTexture("./res/db1/RightS.png");
			state->textures[0].init = true;
			state->textures[1].tex = LoadTexture("./res/db1/LeftS.png");
			state->textures[1].init = true;
			state->textures[2].tex = LoadTexture("./res/db1/Center.png");
			state->textures[2].init = true;
			state->textures[3].tex = LoadTexture("./res/db1/S.png");
			state->textures[3].init = true;

			//SetState(state, STATE_DBINTRO);
			break;
		case STATE_DBINTRO:
			state->bgColor = (Color) { 5, 0, 0, 255 };
			break;
		default: break;
	}
}
float HeavisideEasing(float value, float step) {
	return (float) (atan(((double) (value) - .5) * step) / PI + .5);
}
