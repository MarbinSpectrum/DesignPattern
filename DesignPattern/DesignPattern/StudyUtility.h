#pragma once

#define SAFE_DELETE(x) \
do \
{ \
if(x != NULL) \
{	\
delete x; \
x = NULL; \
} \
}\
while(0) \
	
