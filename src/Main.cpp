//////////////////////////////////////
// Application Entry Point
//////////////////////////////////////
#include "./Engine.h"
#include "./Data/include/OPsharedLibrary.h"

typedef void (*pf)();
OPsharedLibrary* gameCode;
OPsharedLibrarySymbol* init;
OPsharedLibrarySymbol* update;

//////////////////////////////////////
// Application Methods
//////////////////////////////////////

void ApplicationInit() {

	gameCode = OPsharedLibraryLoad("/Users/garretthoofman/shared.library/libShared.dylib");
	if(gameCode == NULL) exit(1);

	init = OPsharedLibraryLoadSymbol(gameCode, "GameInit");
	update = OPsharedLibraryLoadSymbol(gameCode, "GameUpdate");
	((pf)init->Symbol)();
}

int ApplicationUpdate(OPtimer* timer) {
	OPsharedLibraryReload(gameCode);

	((pf)update->Symbol)();
	return 0;
}

void ApplicationDestroy() {

}

void ApplicationSetup() {
	OPinitialize = ApplicationInit;
	OPupdate = ApplicationUpdate;
	OPdestroy = ApplicationDestroy;
}

//////////////////////////////////////
// Application Entry Point
//////////////////////////////////////
OP_MAIN {
	OPlog("Starting up OPifex Engine");

	OPinitialize = ApplicationInit;
	OPupdate = ApplicationUpdate;
	OPdestroy = ApplicationDestroy;

	OP_MAIN_START
	OP_MAIN_END
	OP_MAIN_SUCCESS
}