import os
import chardet
import re
# 获取当前脚本所在路径
def get_current_directory() -> str:
    return os.path.dirname(__file__)

# 获取指定路径下的所有指定类型文件
def get_files(path: str, file_types: tuple) -> list:
    return [f for f in os.listdir(path)
            if os.path.isfile(os.path.join(path, f)) and f.endswith(file_types)]

# 获取指定路径下的所有文件夹
def get_folders(path: str) -> list:
    return [f for f in os.listdir(path) if os.path.isdir(os.path.join(path, f))]

# 获取当前脚本所在路径
folder_path = get_current_directory()

# 忽略的文件列表
neglect_files = {
    '.vs', '.git', 'tool.py', '.gitattributes', '.gitignore', 'out',
    'CMakeLists.txt', 'CMakeSettings.json', 'README.md'
}

# 自动检测文件编码
def get_file_encoding(file_path: str) -> str:
    with open(file_path, 'rb') as f:  # 以二进制模式打开文件
        raw_data = f.read()
        result = chardet.detect(raw_data)
        return result['encoding']

# 尝试用自动检测的编码读取文件
def read_file_with_auto_encoding(file_path: str) -> str:
    encoding = get_file_encoding(file_path)
    with open(file_path, 'r', encoding=encoding) as f:
        return f.read()

# 尝试常见编码读取文件
def read_file_with_fallback(file_path: str) -> str:
    encodings = ['utf-8', 'gbk', 'latin-1']
    for encoding in encodings:
        try:
            with open(file_path, 'r', encoding=encoding) as f:
                return f.read()
        except UnicodeDecodeError:
            continue  # 如果当前编码失败，则继续尝试下一个编码
    raise Exception(f"无法识别文件编码：{file_path}")

# 读取文件内容
def read_file(file_path: str) -> str:
    try:
        # 尝试使用自动检测编码
        return read_file_with_auto_encoding(file_path)
    except Exception:
        # 如果自动检测失败，尝试常见编码
        return read_file_with_fallback(file_path)

# 生成C++类文档
def generate_class_documentation(class_code: str) -> str:
    class_code =  class_code.split('\n')
    for i in range(len(class_code)):
        if 'class' in class_code[i]:
            # 获取类名
            class_name = re.search(r'(?<=class\s)\w+', class_code[i])
            # 获取类注释
            class_comment = ''
            j = 1
            while '//' in class_code[i-j]:
                class_comment = re.search(r'(?<=//)\s*\w+', class_code[i-j]).group(0) + '\n' + class_comment
                j += 1
            

                
            print(class_name.group(0)+'\n',class_comment,'\n')


file_tree = ''

def get_file_tree(path: str, depth: int):
    global neglect_files
    global file_tree
    openfolder = True
    
    try:
        # 读取 description.md 文件内容
        with open(path + '/' + 'description.md', 'r', encoding='utf-8') as description_file:
            description_content = description_file.read()
            file_tree += description_content + '\n'
            # 判断 description.md 是否包含 '*'
            if '*' in description_content:
                openfolder = False
    except FileNotFoundError:
        # 如果 description.md 文件不存在，输出"无说明"
        file_tree += '无说明\n'

    # 如果文件夹没有包含 '*'，则继续遍历子文件夹和文件
    if openfolder:
        for folder in [file for file in get_folders(path) if file not in neglect_files]:
            file_tree += (depth * '    ') + folder + ':'
            get_file_tree(path + '/' + folder, depth + 1)

        # 获取指定类型的文件并列出
        for file in get_files(path, ('.cpp', '.h', '.hpp', '.c', '.txt', '.md')):
            file_tree += (depth * '    ') + file + '\n'
            file_content = read_file(path + '/' + file)  # 使用新加的读取方法
            generate_class_documentation(file_content)

get_file_tree(folder_path, 0)

with open(folder_path + '/README114514.md', 'w') as file:
    file.write(
        f'''
        # Game 项目

目前该项目正处于开发初期

该项目是一个基于 **SFML** 的 Windows 平台游戏，只支持在 **Windows** 上使用 **MSVC** 编译，推荐使用 **Visual Studio (VS)** 作为开发环境。

### 编译要求

- 使用 **C++23** 标准。
- 使用**CMake**构建
- **Windows** 平台。
- 推荐使用 **MSVC** 编译器，并建议使用 **Visual Studio (VS)** 进行开发。

## 文件结构

项目包含两大部分：**游戏内容** 和 **基于 SFML 的游戏框架**。

```目录
{file_tree}
```

### 目录说明

#### `Game` 目录

- **Game**：包含所有与游戏内容相关的源代码和资源。

#### `SFMLUI` 目录

`SFMLUI` 目录包含了基于 **SFML** 的游戏框架，包括资源、头文件、源代码等。

- **assets**：存放所有资源文件，如图片、音频等。
  - **images**：用于存放游戏中使用的图片文件。
- **include**：存放所有游戏框架的头文件，分为核心文件和自定义窗口元素部分。
  - **core**：包含核心模块，负责游戏的基本功能。
    - **message**：处理游戏中的信息和事件。
    - **pages**：处理游戏中的页面和界面。
    - **window**：负责窗口的创建和管理。
  - **customizable**：提供可自定义的窗口元素，如按钮、面板等。
    - **components**：自定义组件（如按钮、面板等）。
    - **controls**：自定义控件（如文本框、滑动条等）。
- **SFML**：包含 **SFML** 的头文件和库文件，供游戏框架使用。
- **src**：存放源代码，和 `include` 目录中的头文件一一对应。
  - **core**：核心功能部分的源代码。
    - **pages**：页面和界面的实现代码。
  - **customizable**：自定义组件和控件的实现代码。

------

### 编译与运行

1. 克隆或下载本项目。
2. 使用 **Visual Studio (VS)** 打开解决方案文件（如果已存在），或通过 **CMake** 构建项目。
3. 确保使用 **MSVC 编译器** 和 **C++23 标准** 进行编译。
666
        '''
    )