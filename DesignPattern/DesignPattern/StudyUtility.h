#pragma once

#define SAFE_DELETE(x) \
if(x != NULL) \
{	\
delete x; \
x = NULL; \
}\
	
