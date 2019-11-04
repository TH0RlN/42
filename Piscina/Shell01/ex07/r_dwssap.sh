#!/bin/bash
cat /etc/passwd | grep -v '^#' | sed '1d; n; d' | cut -d ':' -f1 | rev | sort -r | awk "{if (NR >= $FT_LINE1 && $FT_LINE2 >= NR) print}" | sed 's/$/, /g' | tr -d '\n' | sed 's/, $/./g'
