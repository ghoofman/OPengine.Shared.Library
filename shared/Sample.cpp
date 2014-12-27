#include "./Engine.h"

extern "C" {
	void GameInit();
	void GameUpdate();
}

void GameInit() {

	OPchar* assetDir = NULL;
#ifdef OPIFEX_REPO
	assetDir = OPIFEX_REPO;
#endif
	OPcmanInit(assetDir);

	OPrenderInit();
}

void GameUpdate() {
	OPrenderClear(1.0, 0.75, 0.75);
	OPrenderPresent();
}