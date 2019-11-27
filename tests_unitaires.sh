#!/bin/bash

for file in `cd Tests && find * | grep txt`; do
	./main Tests/$file Hexified/$file
done

exit 0
