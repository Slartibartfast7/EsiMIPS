#!/bin/bash

for file in `cd Tests && find * | grep txt`; do
	./emul-mips -tests Tests/$file Hexified/$file
done

exit 0
