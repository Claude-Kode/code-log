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
        const name = problem.name.replace(/[\\/:*?"<>|]/g, '_');
        const filePath = path.join(targetDir, name + ext);
        results.push(filePath);
    }

    return results;
}