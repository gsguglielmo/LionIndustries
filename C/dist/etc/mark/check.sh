#!/bin/bash
pidmark=$(pidof mark);
if [ "$pidmark" = "" ]; then
	exit 0;
fi
exit 1;
