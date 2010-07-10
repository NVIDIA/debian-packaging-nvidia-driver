#!/bin/sh
# Based on the nvidia_supported script from Ubuntu's nvidia-current package.
#set -e


[ -n "$1" ] || {
  echo "USAGE: $0 path/to/nv/nv-kernel.o" >&2
  exit 1
}

device_ids() {
  local filename="$1"

  local list_prev="$(mktemp)"
  local list_cur="$(mktemp)"

  # Find the symbols of the .rodata section...
  objdump --section=.rodata --syms "$filename" |
  sed -nr 's/^([0-9a-f]+)\s+l\s+O\s+\S+\s+([0-9a-f]+)\s+\S+.*/\1 \2/p' |
  while read start length; do
    objdump --section=.rodata --full-contents \
      --start-address="0x$start" \
      --stop-address="$((0x$start+0x$length))" "$filename" |
    sed -nr 's/^ [0-9a-f]+ ([0-9a-f]{2})([0-9a-f]{2})0000.*/\2\1/p' |
    sort | uniq | grep -vx "0000" >"$list_cur"

    # The consistent thing between different releases has been that there are
    # two subsequent symbols with the same PCI ID list near the beginning. Find
    # them.
    if [ -s "$list_prev" -a -s "$list_cur" ] &&
       cmp -s "$list_prev" "$list_cur"; then
      cat "$list_cur"
      break
    fi

    cp "$list_cur" "$list_prev"
  done

  rm -f "$list_prev" "$list_cur"
}

for id in $(device_ids "$1"); do
  echo 10de$id
done

