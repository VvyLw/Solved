final int w = io.ni(), b = io.ni(), n;
		if(w == 0 && b == 0) {
			io.fin("Yes");
		}
		final String s = "wbwbwwbwbwbw", t;
		final var sb = new StringBuilder();
		iota(20).forEach(i -> sb.append(s));
		t = sb.toString();
		n = t.length();
		boolean ok = false;
		for(int i = 0; i < n; ++i) {
			for(int j = i; ++j < n;) {
				final var u = t.substring(i, j);
				//io.dump(u);
				final var cnt = IntPair.of(0, 0);
				for(final var c: u.toCharArray()) {
					if(c == 'w') {
						cnt.first++;
					} else {
						cnt.second++;
					}
				}
				ok |= cnt.equals(IntPair.of(w, b));
			}
		}
		io.out(yes(ok));