async function process() {
    const lang = await ui.chooseItem(
        ['C++', 'Python'],
        'Choose language'
    );

    if (!lang) return 'Cancelled';

    const isCpp = lang === 'C++';
    const ext = isCpp ? '.cpp' : '.py';

    const root = workspaceFolders[0].path;
    const targetDir = path.join(root, 'src', isCpp ? 'cpp' : 'py', 'problems');

    const results = [];
    for (const problem of problems) {
        const { name, url } = problem;
        let filename = null;

        if (url) {
            try {
                const u = new URL(url);
                const isHost = (host) =>
                    u.hostname === host || u.hostname.endsWith('.' + host);

                if (isHost('codeforces.com')) {
                    const patterns = [
                        /\/contest\/(\d+)\/problem\/(\w+)/,
                        /\/problemset\/problem\/(\d+)\/(\w+)/,
                        /\/gym\/(\d+)\/problem\/(\w+)/
                    ];
                    for (const re of patterns) {
                        const m = url.match(re);
                        if (m) {
                            filename = 'CF_' + m[1] + '_' + m[2];
                            break;
                        }
                    }
                } else if (isHost('luogu.com.cn')) {
                    const m = url.match(/problem\/(\w+)/);
                    if (m) filename = 'LG_' + m[1];
                } else if (isHost('atcoder.jp')) {
                    const m = url.match(/tasks\/(\w+)_(\w+)/);
                    if (m) filename = 'ATC_' + m[1] + '_' + m[2];
                } else if (isHost('qoj.ac')) {
                    const m = url.match(/problem\/(\w+)/);
                    if (m) filename = 'QOJ_' + m[1];
                } else if (isHost('nowcoder.com')) {
                    const m1 = url.match(/\/acm\/contest\/(\d+)\/(\w+)/);
                    if (m1) {
                        filename = 'NC_' + m1[1] + '_' + m1[2];
                    } else {
                        const m2 = url.match(/\/acm\/problem\/(\d+)/);
                        if (m2) filename = 'NC_' + m2[1];
                    }
                }
            } catch (e) {}
        }

        if (!filename) {
            const ascii = name.replace(/[^a-zA-Z0-9]+/g, '_')
                .replace(/^_|_$/g, '');
            if (ascii) {
                filename = ascii;
            } else if (url) {
                const parts = url.replace(/\/$/, '').split('/');
                const last = parts[parts.length - 1];
                if (last && /^[a-zA-Z0-9_]+$/.test(last)) {
                    filename = last;
                }
            }
            if (!filename) {
                filename = 'problem_' + Date.now();
            }
        }

        const filePath = path.join(targetDir, filename + ext);
        results.push(filePath);
    }

    return results;
}
