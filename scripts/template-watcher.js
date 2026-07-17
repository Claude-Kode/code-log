const fs = require('fs');
const path = require('path');

const rootDir = path.dirname(__dirname);
const cppTemplate = fs.readFileSync(path.join(rootDir, 'templates', 'TEMPLATE-2.cpp'), 'utf-8');
const pyTemplate = fs.readFileSync(path.join(rootDir, 'templates', 'TEMPLATE-PY.py'), 'utf-8');

const cppDir = path.join(rootDir, 'src', 'cpp', 'problems');
const pyDir = path.join(rootDir, 'src', 'py', 'problems');

function applyTemplate(filePath) {
    const ext = path.extname(filePath);
    
    if (ext === '.cpp') {
        const content = fs.readFileSync(filePath, 'utf-8');
        if (!content.includes('TEMPLATE-2')) {
            fs.writeFileSync(filePath, cppTemplate);
            console.log(`Applied C++ template to: ${filePath}`);
        }
    } else if (ext === '.py') {
        const content = fs.readFileSync(filePath, 'utf-8');
        if (!content.includes('TEMPLATE-PY')) {
            fs.writeFileSync(filePath, pyTemplate);
            console.log(`Applied Python template to: ${filePath}`);
        }
    }
}

function watchDir(dir) {
    if (!fs.existsSync(dir)) {
        fs.mkdirSync(dir, { recursive: true });
    }
    
    fs.watch(dir, (eventType, filename) => {
        if (eventType === 'rename' && filename) {
            const filePath = path.join(dir, filename);
            setTimeout(() => {
                if (fs.existsSync(filePath)) {
                    applyTemplate(filePath);
                }
            }, 100);
        }
    });
    
    console.log(`Watching directory: ${dir}`);
}

watchDir(cppDir);
watchDir(pyDir);

console.log('\nTemplate watcher is running...');
console.log('Press Ctrl+C to stop');

process.on('SIGINT', () => {
    console.log('\nStopping template watcher...');
    process.exit(0);
});