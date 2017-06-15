#pragma once
#include <SDL.h>
#include <queue>
#include <functional>
#include <SDL_mixer.h>
#include <vector>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <chrono>
#include "SceneManager.h"
#include "Box2D\Box2D.h"

const int physicsFrameLock = 60;
const int velocityIterations = 8;
const int positionIterations = 3;

class RPGSAEMMOApp
{
public:
	inline static SDL_Window* getWindow() { return window; }
	inline static SDL_Surface* getRenderSurface() { return renderSurface; }
	inline static SDL_Renderer* getRenderer() { return renderer;}
	inline static SDL_Texture* getRenderTexture() { return renderTexture; }
	inline static SDL_mutex* getMutex() { return drawMutex; }
	inline static long long getDeltaTime() { return dT; }
	inline static float getScalingFactor() { return scalingFactor; }
	inline static std::chrono::milliseconds getPhysicsTimeSinceStart() { return physicsTimeSinceStart; }
	inline static b2World* getWorld() { return world == nullptr ? world = new b2World(gravity) : world; }
	inline static b2Vec2 getGravity() { return gravity; }
	inline static bool QueueHasCleared() { return queueIsCleared; }
	inline static bool ApplicationIsClosing() { return appIsClosing; }
	inline static void LockDrawMutex() { SDL_LockMutex(drawMutex); }
	inline static void UnlockDrawMutex() { SDL_UnlockMutex(drawMutex); }
	inline static void ApplicationShouldClose(SDL_bool val) { appIsClosing = val; }
	static int GetFrameLock();
	static int getWidth();
	static int getHeight();
	static float scalingConst;
	static void ClearDrawQueue();
	static void AddToDrawQueue(std::function<void()> f);
	static void AddToPhysicsQueue(std::function<void()> f);
	static void ChangeFrameLock(const int& fps = 60);
	static void PrintSurfacesToScreen(const std::vector<SDL_Surface*>& surfaces,
		const std::vector<SDL_Rect*>& srcRects, const std::vector<SDL_Rect*>& dstRects);
	void App(const int& sizeX, const int& sizeY,
		const char* WindowTitle, const uint32_t parameters, int fps,
		Scene* const& mainScene, const b2Vec2& _gravity, const float& scale);
	static fVector2 camera;
private:
	void Init();
	static int Draw(void *ptr);
	static int Physics(void *ptr);
	static long long dT;
	static void DrawStep();
	static SDL_Window *window;
	static SDL_Renderer *renderer;
	static SDL_Texture *renderTexture;
	static SDL_Surface *renderSurface;
	SDL_Event event;
	SDL_Thread *drawThread;
	SDL_Thread *physicsThread;
	uint32_t winParams;
	static SDL_mutex* drawMutex;
	static SDL_mutex* physicsMutex;
	static std::queue<std::function<void()>> drawQueue;
	static std::queue<std::function<void()>> physicsQueue;
	static SDL_bool appIsClosing;
	static int frameLock;
	static int windowSizeX;
	static int windowSizeY;
	static bool queueIsCleared;
	static std::chrono::milliseconds physicsTimeSinceStart;
	static std::chrono::milliseconds physicsTimeStart;
	static std::chrono::milliseconds deltaTime;
	static b2Vec2 gravity; 
	static b2World* world;
	static float scalingFactor;
};

inline b2Vec2 ToMetricSystem(float _x, float _y) {
	if (RPGSAEMMOApp::scalingConst == 0) 
		RPGSAEMMOApp::scalingConst = 1 / RPGSAEMMOApp::getScalingFactor();
	return b2Vec2(_x*RPGSAEMMOApp::scalingConst, _y*RPGSAEMMOApp::scalingConst);
}