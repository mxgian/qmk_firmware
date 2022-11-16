#!/bin/bash
#zip archive -@ < keeblist
user="/keymaps/minh"
prefix="keyboards/"
keeblist=("ai03/lunar"
"ai03/equinox"
"crkbd"
"cannonkeys/instant60"
"espectro"
"hadron/ver3"
"hb85"
"gray_studio/hb85"
"hineybush/h87a"
"wsk/jerkin"
"keebio/bdn9"
"keebio/dsp40"
"mechlovin/adelais"
"planck"
"planck"
"primekb/prime_e"
"tr60w"
"thevankeyboards/bananasplit"
"thevankeyboards/minivan"
"thevankeyboards/roadkit"
"thevankeyboards/v4n4g0n"
"trashman/ketch"
"walletburner/cajal"
"walletburner/neuron"

)
for i in "${keeblist[@]}"
do
	echo "$prefix$i$user"
done

#special code
extrakeebs=("planck/keymaps/minh-2spc")
#grab the keebs that are custom or dont have a folder
custom="minh"

#git add commands
for i in "${keeblist[@]}"
do
	echo "git add $prefix$i$user"
done
