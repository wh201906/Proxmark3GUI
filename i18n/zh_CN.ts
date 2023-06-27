<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="zh_CN">
<context>
    <name>MF_Attack_hardnestedDialog</name>
    <message>
        <location filename="../src/ui/mf_attack_hardnesteddialog.ui" line="14"/>
        <source>Hardnested Attack</source>
        <translation>Hardnested攻击</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_attack_hardnesteddialog.ui" line="20"/>
        <source>Known Block:</source>
        <translation>已知块：</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_attack_hardnesteddialog.ui" line="29"/>
        <location filename="../src/ui/mf_attack_hardnesteddialog.ui" line="104"/>
        <source>Block:</source>
        <translation>块：</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_attack_hardnesteddialog.ui" line="68"/>
        <location filename="../src/ui/mf_attack_hardnesteddialog.ui" line="143"/>
        <source>A</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_attack_hardnesteddialog.ui" line="73"/>
        <location filename="../src/ui/mf_attack_hardnesteddialog.ui" line="148"/>
        <source>B</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_attack_hardnesteddialog.ui" line="95"/>
        <source>Target Block:</source>
        <translation>目标块：</translation>
    </message>
</context>
<context>
    <name>MF_Sim_simDialog</name>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="14"/>
        <source>Simulate</source>
        <translation>模拟</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="67"/>
        <source>UID 4 or 7 bytes. If not specified, the UID 4B from emulator memory will be used</source>
        <translation>4或7字节的UID，如果不指定，则使用模拟器内存中的4字节UID</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="134"/>
        <source>Provide explicit ATQA (2 bytes)</source>
        <translation>指定ATQA（2个字节）</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="201"/>
        <source>Provide explicit SAK (1 byte)</source>
        <translation>指定SAK（1个字节）</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="268"/>
        <source>Automatically exit simulation after &lt;numreads&gt; blocks have been read by reader. 0 = infinite</source>
        <translation>在读卡器读取&lt;n&gt;个块后自动退出模拟，n为0或不指定时永远不退出</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="319"/>
        <source>Interactive, means that console will not be returned until simulation finishes or is aborted</source>
        <translation>交互模式，勾选后PM3客户端将在模拟完成或者模拟中断后才可继续使用</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="370"/>
        <source>Crack, performs the &apos;reader attack&apos;, nr/ar attack against a legitimate reader, fishes out the key(s)</source>
        <translation>破解，对读卡器进行攻击，通过nr/ar攻击来钓出密码(无卡嗅探)</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="421"/>
        <source>set keys found from &apos;reader attack&apos; to emulator memory (implies x(--crack) and i)</source>
        <translation>在获得密码后自动将密码写入模拟器内存（自动勾选x(--crack)和i）</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="590"/>
        <source>verbose output</source>
        <translation>更多输出内容</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="488"/>
        <source>get UIDs to use for &apos;reader attack&apos; from file &apos;f &lt;filename.txt&gt;&apos; (implies x and i)</source>
        <translation>从&lt;filename.txt&gt;当中获取用于破解读卡器的UID（批量模拟）（自动勾选x和i）</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="539"/>
        <source>Generate random nonces instead of sequential nonces. Standard reader attack won&apos;t work with this option, only moebius attack works</source>
        <translation>生成随机nonce而不是顺序的nonce，这种情况下PM3将不对读卡器进行标准攻击，只进行moebius攻击</translation>
    </message>
</context>
<context>
    <name>MF_UID_parameterDialog</name>
    <message>
        <location filename="../src/ui/mf_uid_parameterdialog.ui" line="14"/>
        <source>Set Parameter</source>
        <translation>设置卡参数</translation>
    </message>
</context>
<context>
    <name>MF_trailerDecoderDialog</name>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="14"/>
        <source>Trailer Decoder</source>
        <translation>Trailer解码</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="22"/>
        <source>Blocks</source>
        <translation>块大小</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="67"/>
        <source>Trailer Data:
(like &quot;FF0780&quot; or &quot;FF 07 80&quot;)</source>
        <translation>输入控制位数据
（形如“FF0780”或“FF 07 80”）</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="120"/>
        <source>Or set bits manually</source>
        <translation>手动设置访问情况：</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="323"/>
        <source>Data Block Permission:</source>
        <translation>数据块访问权限：</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="340"/>
        <source>Block0</source>
        <translation>块0</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="345"/>
        <source>Block1</source>
        <translation>块1</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="350"/>
        <source>Block2</source>
        <translation>块2</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="355"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="395"/>
        <source>Read</source>
        <translation>读</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="360"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="400"/>
        <source>Write</source>
        <translation>写</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="365"/>
        <source>Increase</source>
        <translation>增加</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="370"/>
        <source>Decrease/Transfer/Restore</source>
        <translation>减少/从缓冲区写入/读入至缓冲区</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="378"/>
        <source>Trailer Block Permission:</source>
        <translation>Trailer访问权限：</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="405"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="130"/>
        <source>KeyA</source>
        <translation>密钥A</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="410"/>
        <source>Access Bits</source>
        <translation>控制位</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="415"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="134"/>
        <source>KeyB</source>
        <translation>密钥B</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="425"/>
        <source>Reference:
MF1S70YYX_V1 Product data sheet
Rev. 3.2 — 23 November 2017</source>
        <translation>参考资料：
MF1S70YYX_V1 Product data sheet
Rev. 3.2 — 23 November 2017</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="446"/>
        <source>Note:the Access Bits usually contains 4 bytes(8 hex symbols), but only the first 3 bytes matters. You can set the 4th byte randomly.</source>
        <translation>注意：Access Bits一般包含4个字节（8个16进制字符），但只有前3个字节决定访问情况，最后一个字节可任意设置。</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="45"/>
        <source>Invalid!
It could make the whole sector blocked irreversibly!</source>
        <translation>无效！
可能导致整个扇区被不可逆转地锁定！</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="83"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="88"/>
        <source>Valid</source>
        <translation>有效</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="83"/>
        <source>KeyB cannot serve for authentication</source>
        <translation>密钥B无法用于认证</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="105"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="106"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="107"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="111"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="112"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="113"/>
        <source>Block</source>
        <translation>块</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="138"/>
        <source>KeyA+B</source>
        <translation>密钥A+B</translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="20"/>
        <source>Proxmark3GUI</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="124"/>
        <source>Connect</source>
        <translation>连接</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="137"/>
        <source>Disconnect</source>
        <translation>断开</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="156"/>
        <source>Mifare</source>
        <translation>Mifare(IC)卡</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="259"/>
        <source>Select Trailer</source>
        <translation>选中密码块</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="402"/>
        <source>Card Type</source>
        <translation>卡片类型</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="423"/>
        <source>MINI</source>
        <extracomment>320</extracomment>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="436"/>
        <source>1K</source>
        <extracomment>1024</extracomment>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="452"/>
        <source>2K</source>
        <extracomment>2048</extracomment>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="465"/>
        <source>4K</source>
        <extracomment>4096</extracomment>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="475"/>
        <source>File</source>
        <translation>文件</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="496"/>
        <location filename="../src/ui/mainwindow.ui" line="1202"/>
        <source>Load</source>
        <translation>加载</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="509"/>
        <location filename="../src/ui/mainwindow.ui" line="1215"/>
        <source>Save</source>
        <translation>保存</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="226"/>
        <location filename="../src/ui/mainwindow.ui" line="529"/>
        <source>Data</source>
        <translation>数据</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="539"/>
        <source>Key</source>
        <translation>密钥</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="549"/>
        <source>Attack</source>
        <translation>破解</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="583"/>
        <source>Card Info</source>
        <translation>读卡信息</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="596"/>
        <source>Check Default</source>
        <translation>验证默认密码</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="609"/>
        <source>Nested</source>
        <translation>Nested攻击</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="622"/>
        <source>Hardnested</source>
        <translation>Hardested攻击</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="635"/>
        <source>Darkside</source>
        <translation>Darkside攻击</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="660"/>
        <source>Read/Write</source>
        <translation>读/写</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="673"/>
        <source>Block:</source>
        <translation>块：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="705"/>
        <source>Key:</source>
        <translation>密钥：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="724"/>
        <source>Key Type:</source>
        <translation>密钥类型：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1189"/>
        <source>List Data</source>
        <translation>列出嗅探数据</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="747"/>
        <location filename="../src/ui/mainwindow.ui" line="2403"/>
        <source>Data:</source>
        <translation>数据：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="769"/>
        <source>Normal(Require Password)</source>
        <translation>普通卡（需要密码）</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="851"/>
        <source>Dump</source>
        <translation>Dump命令</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="870"/>
        <source>Restore</source>
        <translation>Restore命令</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="880"/>
        <source>Chinese Magic Card(Without Password)</source>
        <translation>UID卡（不需要密码）</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="901"/>
        <source>Lock UFUID Card</source>
        <translation>锁定UFUID卡</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="914"/>
        <location filename="../src/ui/mainwindow.cpp" line="916"/>
        <source>About UID Card</source>
        <translation>关于UID卡</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="985"/>
        <source>Set Parameter</source>
        <translation>设置卡参数</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1004"/>
        <source>Wipe</source>
        <translation>擦除</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1030"/>
        <location filename="../src/ui/mainwindow.ui" line="1106"/>
        <source>Simulate</source>
        <translation>模拟</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="522"/>
        <location filename="../src/ui/mainwindow.ui" line="1093"/>
        <source>Clear</source>
        <translation>清空</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="56"/>
        <source>Client Path:</source>
        <translation>客户端路径：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="82"/>
        <source>Port:</source>
        <translation>端口：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="111"/>
        <source>Refresh Ports</source>
        <translation>刷新端口</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="252"/>
        <source>Select All</source>
        <translation>全选</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="288"/>
        <source>KeyBlocks-&gt;Key</source>
        <translation>密码区-&gt;密码</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="301"/>
        <source>KeyBlocks&lt;-Key</source>
        <translation>密码区&lt;-密码</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="314"/>
        <source>Fill Keys</source>
        <translation>填充密码</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="327"/>
        <source>Trailer Decoder</source>
        <translation>Trailer解码</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="793"/>
        <location filename="../src/ui/mainwindow.ui" line="927"/>
        <source>Read One</source>
        <translation>读取单个块</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="806"/>
        <location filename="../src/ui/mainwindow.ui" line="940"/>
        <source>Write One</source>
        <translation>写入单个块</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="819"/>
        <location filename="../src/ui/mainwindow.ui" line="953"/>
        <location filename="../src/ui/mainwindow.ui" line="1080"/>
        <source>Read Selected</source>
        <translation>读取选中块</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="832"/>
        <location filename="../src/ui/mainwindow.ui" line="966"/>
        <location filename="../src/ui/mainwindow.ui" line="1067"/>
        <source>Write Selected</source>
        <translation>写入选中块</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1129"/>
        <location filename="../src/ui/mainwindow.ui" line="1163"/>
        <location filename="../src/ui/mainwindow.ui" line="1800"/>
        <source>Sniff</source>
        <translation>嗅探</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1176"/>
        <source>Sniff(14a)</source>
        <translation>嗅探(14a)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1252"/>
        <source>LF Config</source>
        <translation>低频配置</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1273"/>
        <source>Frequency</source>
        <translation>频率</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1396"/>
        <source>You might need a modified LF antenna if the freq is not 125k/134k.
When setting the freq, the &quot;hw setlfdivisor&quot; will also be called.</source>
        <translation>如果频率不为125k/134k，则原装天线可能不适用。
设置频率后GUI会使用&quot;hw setlfdivisor&quot;改变底层分频系数。</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1427"/>
        <source>Bits per sample:</source>
        <translation>采样精度(Bits per sample)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1434"/>
        <source>Decimation:</source>
        <translation>抽取(Decimation)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1451"/>
        <source>Averaging:</source>
        <translation>平均化(Averaging)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1576"/>
        <source>Reset</source>
        <translation>重置</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1601"/>
        <source>LF Operation</source>
        <translation>低频操作</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1626"/>
        <source>Search</source>
        <translation>搜索</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1657"/>
        <source>Read and search for valid known tag.</source>
        <translation>读卡并寻找已知类型的卡</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1683"/>
        <source>Read</source>
        <translation>读取</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1714"/>
        <source>Sniff low frequency signal with LF field ON.
Use this to get raw data from a tag.</source>
        <translation>激活低频电磁场并读取原始信号。
该功能用于获取卡片原始数据。</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1741"/>
        <source>Tune</source>
        <translation>调谐</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1772"/>
        <source>Measure LF antenna tuning.
If the antenna voltage has a obvious drop after putting card on the antenna, it is likely that the tag is a LF tag.
On Iceman/RRG repo, press the button on PM3 to stop measuring</source>
        <translation>测量低频天线谐振频率。
如果天线电压在放置卡片后明显下降，则该卡片很可能是低频卡。
在冰人版固件下，如果需要停止测量，请按下PM3侧面的按钮</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1831"/>
        <source>Sniff low frequency signal with LF field OFF.
Use this to get raw data from a reader 
or the communication between a tag and a reader.</source>
        <translation>直接读取低频信号。
该功能用于获取读卡器的数据
或者卡片与读卡器的交互过程。</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1883"/>
        <location filename="../src/ui/mainwindow.cpp" line="48"/>
        <source>T55xx</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1895"/>
        <source>Basic Configuration(Page 0 Block 0)</source>
        <translation>基本配置区(页0 块0)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1909"/>
        <location filename="../src/ui/mainwindow.ui" line="2185"/>
        <source>Hex:</source>
        <translation>16进制：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1916"/>
        <location filename="../src/ui/mainwindow.ui" line="2192"/>
        <source>Bin:</source>
        <translation>2进制：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1960"/>
        <location filename="../src/ui/mainwindow.ui" line="2236"/>
        <source>Get from Data</source>
        <translation>从数据区导入</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1967"/>
        <location filename="../src/ui/mainwindow.ui" line="2243"/>
        <source>Set to Data</source>
        <translation>导出到数据区</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1997"/>
        <location filename="../src/ui/mainwindow.ui" line="2276"/>
        <source>Locked:</source>
        <translation>锁定(Locked)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2007"/>
        <source>Master Key:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2014"/>
        <source>Data Bit Rate:</source>
        <translation>数据比特率(Data Bit Rate)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2024"/>
        <source>eXtended Mode:</source>
        <translation>扩展模式(eXtended Mode)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2031"/>
        <location filename="../src/ui/mainwindow.ui" line="2430"/>
        <source>Modulation:</source>
        <translation>调制方式(Modulation)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2038"/>
        <source>PSK Clock Freq:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2045"/>
        <source>Answer on Request:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2058"/>
        <source>One Time Pad:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2065"/>
        <source>Max Block:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2072"/>
        <source>Password:</source>
        <translation>密码(Password):</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2079"/>
        <source>Seq. Terminator:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2086"/>
        <source>Seq. Start Marker:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2093"/>
        <source>Fast Downlink:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2100"/>
        <source>Inverse Data:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2107"/>
        <source>Init-Delay:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2171"/>
        <source>Analog Front-End Option(Page 1 Block 3)</source>
        <translation>模拟前端选项区(页1 块3)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2286"/>
        <source>Option Key:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2296"/>
        <source>Soft Modulation:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2306"/>
        <source>Clamp Voltage:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2316"/>
        <source>Modulation Voltage:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2326"/>
        <source>Clock Detection Threshold:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2336"/>
        <source>Gap Detection Threshold:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2346"/>
        <source>Write Dampling:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2353"/>
        <source>Demod Delay:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2360"/>
        <source>Downlink Protocol:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2422"/>
        <source>T55xx Read Config</source>
        <translation>T55xx读卡配置区</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2437"/>
        <source>Bit Rate:</source>
        <translation>比特率(Bit Rate)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2444"/>
        <source>Seq. Term.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2451"/>
        <source>Offset:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2458"/>
        <source>Inverted:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2492"/>
        <source>T5577</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2499"/>
        <source>T5555</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2523"/>
        <source>RawCommand</source>
        <translation>原始命令</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2570"/>
        <location filename="../src/ui/mainwindow.cpp" line="360"/>
        <source>History:</source>
        <translation>命令历史：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2602"/>
        <source>ClearHistory</source>
        <translation>清空历史</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2625"/>
        <source>Send</source>
        <translation>发送</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2632"/>
        <source>ClearOutput</source>
        <translation>清空输出</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2642"/>
        <source>Settings</source>
        <translation>设置</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2689"/>
        <source>Client</source>
        <translation>客户端</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2695"/>
        <source>GUI working directory:</source>
        <translation>GUI工作路径：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2730"/>
        <source>If the client requires some enviroment variables, you can make a script file(*.bat on Windows or *.sh on Linux) to configure them, then put the path of the script there.
The &quot;&lt;client dir&gt;&quot; will be replaced by the directory of the &quot;Client Path&quot;</source>
        <translation>如果客户端需要配置环境变量才能正常运行，可以将配置环境变量所需的脚本文件(Windows系统内为*.bat，linux系统内为*.sh)路径填入此处。
当中的&lt;client dir&gt;会被替换为“客户端路径”所对应的父目录</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2755"/>
        <source>../data</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2786"/>
        <source>&lt;port&gt; -f</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2810"/>
        <source>Config file(Reconnect to apply):</source>
        <translation>配置文件(重连后生效)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2953"/>
        <source>UI</source>
        <translation>界面</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2961"/>
        <source>Language: </source>
        <translation>语言： </translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2968"/>
        <source>Choose Language</source>
        <translation>选择语言</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2975"/>
        <source>(Restart this app to use new language)</source>
        <translation>（重启此程序以使用新语言）</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="3012"/>
        <source>Opacity:</source>
        <translation>透明度：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="3056"/>
        <source>Theme:</source>
        <translation>主题：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="3073"/>
        <location filename="../src/ui/mainwindow.ui" line="3114"/>
        <location filename="../src/ui/mainwindow.ui" line="3148"/>
        <location filename="../src/ui/mainwindow.ui" line="3182"/>
        <source>Set</source>
        <translation>设置</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="3080"/>
        <source>(Restart this app to use new theme)</source>
        <translation>（重启此程序以使用新主题）</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="3091"/>
        <source>Global Font:</source>
        <translation>全局字体：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="3125"/>
        <source>Data Font:</source>
        <translation>数据字体：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="3159"/>
        <source>Command Font:</source>
        <translation>命令字体：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="3196"/>
        <source>Latest Release:</source>
        <translation>检查更新：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="3226"/>
        <source>Report Bugs:</source>
        <translation>反馈问题：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2892"/>
        <source>Keep buttons enabled even the client is running or disconnected</source>
        <translation>保持所有按钮可点击，即使未连接客户端或有任务正在运行</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1244"/>
        <source>LF</source>
        <translation>低频</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1331"/>
        <source>other</source>
        <translation>其它</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1338"/>
        <source>Divisor:</source>
        <translation>分频系数(Divisor)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1358"/>
        <source>Actural Freq: 125.000kHz</source>
        <translation>实际频率： 125.000kHz</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1465"/>
        <source>Trigger threshold:</source>
        <translation>触发阈值(Trigger threshold)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1479"/>
        <source>Samples to skip:</source>
        <translation>跳过前n个采样(Samples to skip)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1550"/>
        <source>Get Config</source>
        <translation>获取当前配置</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1569"/>
        <source>Set Config</source>
        <translation>改变当前配置</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2716"/>
        <source>Preload script path(Reconnect to apply):</source>
        <translation>预加载脚本路径(重连后生效)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2748"/>
        <source>Client working directory(Reconnect to apply):</source>
        <translation>客户端工作路径(重连后生效)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2762"/>
        <source>On Windows, the client working directory should not be identical to the path of GUI, otherwise the client will use the wrong .dll file.</source>
        <translation>在Windows系统中，客户端工作路径与GUI程序所在路径不能相同，否则客户端会使用错误的.dll文件。</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2779"/>
        <source>Start arguments(Reconnect to apply):</source>
        <translation>启动参数(重连后生效)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2793"/>
        <source>-f is necessary because the GUI need to handle the output in time. In some cases, the arguments should be set to &quot;-p /dev/&lt;port&gt; -f&quot; or &quot;-p &lt;port&gt; -f&quot;.</source>
        <translation>-f选项用于使客户端实时返回命令回显，必须添加。部分情况下启动参数需设置为&quot;-p /dev/&lt;port&gt; -f&quot;或&quot;-p &lt;port&gt; -f&quot;。</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2841"/>
        <source>config.json</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2848"/>
        <source>Different clients require different config files. You can change the content of config file if the command format changes.</source>
        <translation>不同客户端需要使用不同的配置文件。若命令格式发生改变，你可以尝试手动修改配置文件以适配。</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2938"/>
        <source>Keep the client active even the PM3 hardware is disconnected.(Experimental)</source>
        <translation>在PM3断开后保持客户端运行（实验性功能）</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="91"/>
        <location filename="../src/ui/mainwindow.cpp" line="198"/>
        <location filename="../src/ui/mainwindow.cpp" line="205"/>
        <location filename="../src/ui/mainwindow.cpp" line="277"/>
        <location filename="../src/ui/mainwindow.cpp" line="282"/>
        <location filename="../src/ui/mainwindow.cpp" line="463"/>
        <location filename="../src/ui/mainwindow.cpp" line="677"/>
        <location filename="../src/ui/mainwindow.cpp" line="697"/>
        <location filename="../src/ui/mainwindow.cpp" line="710"/>
        <location filename="../src/ui/mainwindow.cpp" line="729"/>
        <location filename="../src/ui/mainwindow.cpp" line="742"/>
        <location filename="../src/ui/mainwindow.cpp" line="769"/>
        <location filename="../src/ui/mainwindow.cpp" line="782"/>
        <location filename="../src/ui/mainwindow.cpp" line="987"/>
        <location filename="../src/ui/mainwindow.cpp" line="1028"/>
        <source>Info</source>
        <translation>信息</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="205"/>
        <source>Plz choose a port first</source>
        <translation>请先选择端口</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="293"/>
        <source>Connected</source>
        <translation>已连接</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="299"/>
        <location filename="../src/ui/mainwindow.cpp" line="1113"/>
        <source>Not Connected</source>
        <translation>未连接</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="729"/>
        <location filename="../src/ui/mainwindow.cpp" line="742"/>
        <location filename="../src/ui/mainwindow.cpp" line="987"/>
        <source>Failed to open</source>
        <translation>无法打开</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="463"/>
        <source>Continue?</source>
        <translation>确定？</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="12"/>
        <source>Dock all windows</source>
        <translation>吸附所有悬浮窗口</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="14"/>
        <source>Ver: </source>
        <translation>版本： </translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="15"/>
        <source>Check Update</source>
        <translation>检查更新</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="91"/>
        <source>Failed to load config file</source>
        <translation>无法打开配置文件</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="277"/>
        <source>Failed to start the client</source>
        <translation>无法启动客户端</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="282"/>
        <source>Failed to connect to the hardware</source>
        <translation>无法连接到PM3硬件</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="463"/>
        <source>Some of the data and key will be cleared.</source>
        <translation>部分数据和密码将被清除</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="677"/>
        <source>Data must consists of 32 Hex symbols(Whitespace is allowed)</source>
        <translation>数据必须由32个十六进制字符组成（中间可含有空格）</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="697"/>
        <location filename="../src/ui/mainwindow.cpp" line="710"/>
        <source>Key must consists of 12 Hex symbols(Whitespace is allowed)</source>
        <translation>密钥必须由12个十六进制字符组成（中间可含有空格）</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="722"/>
        <source>Plz select the data file:</source>
        <translation>请选择数据文件：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="723"/>
        <location filename="../src/ui/mainwindow.cpp" line="763"/>
        <location filename="../src/ui/mainwindow.cpp" line="767"/>
        <source>Binary Data Files(*.bin *.dump)</source>
        <translation>二进制数据文件(*.bin *.dump)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="723"/>
        <location filename="../src/ui/mainwindow.cpp" line="736"/>
        <location filename="../src/ui/mainwindow.cpp" line="974"/>
        <source>All Files(*.*)</source>
        <translation>所有文件(*.*)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="735"/>
        <source>Plz select the key file:</source>
        <translation>请选择密钥文件：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="762"/>
        <source>Plz select the location to save data file:</source>
        <translation>请选择数据文件保存的位置：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="769"/>
        <location filename="../src/ui/mainwindow.cpp" line="782"/>
        <location filename="../src/ui/mainwindow.cpp" line="1028"/>
        <source>Failed to save to</source>
        <translation>无法保存至</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="775"/>
        <source>Plz select the location to save key file:</source>
        <translation>请选择密钥文件保存的位置：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="736"/>
        <location filename="../src/ui/mainwindow.cpp" line="776"/>
        <location filename="../src/ui/mainwindow.cpp" line="780"/>
        <source>Binary Key Files(*.bin *.dump)</source>
        <translation>二进制密码文件(*.bin *.dump)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="198"/>
        <source>The client path is invalid</source>
        <translation>客户端路径无效</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="723"/>
        <location filename="../src/ui/mainwindow.cpp" line="763"/>
        <source>Text Data Files(*.txt *.eml)</source>
        <translation>文本数据文件(*.txt *.eml)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="901"/>
        <source>    Normally, the Block 0 of a typical Mifare card, which contains the UID, is locked during the manufacture. Users cannot write anything to Block 0 or set a new UID to a normal Mifare card.</source>
        <translation>    普通Mifare卡的块0无法写入，卡号也不能更改</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="902"/>
        <source>    Chinese Magic Cards(aka UID Cards) are some special cards whose Block 0 are writeable. And you can change UID by writing to it.</source>
        <translation>    UID卡（在国外叫Chinese Magic Card）的块0可写，卡号可变。</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="904"/>
        <source>There are two versions of Chinese Magic Cards, the Gen1 and the Gen2.</source>
        <translation>国外把UID卡分为Chinese Magic Card Gen1和Gen2</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="905"/>
        <source>    Gen1:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="905"/>
        <source>    also called UID card in China. It responses to some backdoor commands so you can access any blocks without password. The Proxmark3 has a bunch of related commands(csetblk, cgetblk, ...) to deal with this type of card, and my GUI also support these commands.</source>
        <translation>    指通常所说的UID卡，可以通过后门指令直接读写块而无需密码，在PM3和此GUI中有特殊命令处理这类卡片</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="906"/>
        <source>    Gen2:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="906"/>
        <source>    doesn&apos;t response to the backdoor commands, which means that a reader cannot detect whether it is a Chinese Magic Card or not by sending backdoor commands.</source>
        <translation>    这个叫法在国内比较罕见，在国外指CUID/FUID/UFUID这类对后门指令不响应的卡（防火墙卡）</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="908"/>
        <source>There are some types of Chinese Magic Card Gen2.</source>
        <translation>以下是Gen2卡的详细介绍</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="909"/>
        <source>    CUID Card:</source>
        <translation>    CUID卡：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="909"/>
        <source>    the Block 0 is writeable, you can write to this block repeatedly by normal wrbl command.</source>
        <translation>    可通过普通的写块命令来写块0，可重复擦写</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="910"/>
        <source>    (hf mf wrbl 0 A FFFFFFFFFFFF &lt;the data you want to write&gt;)</source>
        <translation>    (hf mf wrbl 0 A FFFFFFFFFFFF &lt;待写入数据&gt;)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="911"/>
        <source>    FUID Card:</source>
        <translation>    FUID卡：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="911"/>
        <source>    you can only write to Block 0 once. After that, it seems like a typical Mifare card(Block 0 cannot be written to).</source>
        <translation>    块0只能写入一次</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="912"/>
        <source>    (some readers might try changing the Block 0, which could detect the CUID Card. In that case, you should use FUID card.)</source>
        <translation>    (更高级的穿防火墙卡，可以过一些能识别出CUID卡的读卡器)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="913"/>
        <source>    UFUID Card:</source>
        <translation>    UFUID卡：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="913"/>
        <source>    It behaves like a CUID card(or UID card? I&apos;m not sure) before you send some special command to lock it. Once it is locked, you cannot change its Block 0(just like a typical Mifare card).</source>
        <translation>    锁卡前和普通UID/CUID卡一样可以反复读写块0，用特殊命令锁卡后就和FUID卡一样了</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="915"/>
        <source>    Seemingly, these Chinese Magic Cards are more easily to be compromised by Nested Attack(it takes little time to get an unknown key).</source>
        <translation>    所有UID卡都似乎更容易被Nested攻击破解</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="973"/>
        <source>Plz select the trace file:</source>
        <translation>请选择trace文件：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="974"/>
        <location filename="../src/ui/mainwindow.cpp" line="1011"/>
        <source>Trace Files</source>
        <translation>Trace文件</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1010"/>
        <source>Plz select the location to save trace file:</source>
        <translation>请选择trace文件保存的位置：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1138"/>
        <source>(None)</source>
        <translation>(无)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1139"/>
        <source>Dark</source>
        <translation>暗黑</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1140"/>
        <source>Light</source>
        <translation>明亮</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1201"/>
        <source>External file</source>
        <translation>外部文件</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1114"/>
        <location filename="../src/ui/mainwindow.cpp" line="1371"/>
        <source>Idle</source>
        <translation>空闲</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1116"/>
        <source>Stop</source>
        <translation>停止</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="216"/>
        <location filename="../src/ui/mainwindow.ui" line="380"/>
        <source>Sec</source>
        <translation>扇区</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="221"/>
        <source>Blk</source>
        <translation>块</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="385"/>
        <source>KeyA</source>
        <translation>密钥A</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="390"/>
        <source>KeyB</source>
        <translation>密钥B</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1308"/>
        <source>HW Version:</source>
        <translation>固件版本：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1310"/>
        <source>PM3:</source>
        <translation>连接状态：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1312"/>
        <source>State:</source>
        <translation>运行状态：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1367"/>
        <source>Running</source>
        <translation>正在运行</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1555"/>
        <source>Actural Freq: </source>
        <translation>实际频率： </translation>
    </message>
</context>
<context>
    <name>Mifare</name>
    <message>
        <location filename="../src/module/mifare.cpp" line="650"/>
        <location filename="../src/module/mifare.cpp" line="721"/>
        <source>Succeed!</source>
        <translation>成功！</translation>
    </message>
    <message>
        <location filename="../src/module/mifare.cpp" line="216"/>
        <location filename="../src/module/mifare.cpp" line="650"/>
        <location filename="../src/module/mifare.cpp" line="654"/>
        <location filename="../src/module/mifare.cpp" line="678"/>
        <location filename="../src/module/mifare.cpp" line="721"/>
        <location filename="../src/module/mifare.cpp" line="734"/>
        <location filename="../src/module/mifare.cpp" line="791"/>
        <source>Info</source>
        <translation>信息</translation>
    </message>
    <message>
        <location filename="../src/module/mifare.cpp" line="216"/>
        <source>Plz provide at least one known key</source>
        <translation>请至少提供一个已知密码</translation>
    </message>
    <message>
        <location filename="../src/module/mifare.cpp" line="475"/>
        <location filename="../src/module/mifare.cpp" line="654"/>
        <source>Failed!</source>
        <translation>失败！</translation>
    </message>
    <message>
        <location filename="../src/module/mifare.cpp" line="679"/>
        <source>The Access Bits is invalid!
It could make the whole sector blocked irreversibly!
Continue to write?</source>
        <translation>控制位无效！
使用该控制位可能导致目标扇区损坏且无法恢复！
确定要写入吗？</translation>
    </message>
    <message>
        <location filename="../src/module/mifare.cpp" line="734"/>
        <source>Failed to write to these blocks:</source>
        <translation>写入以下块失败：</translation>
    </message>
    <message>
        <location filename="../src/module/mifare.cpp" line="738"/>
        <source>Select them?</source>
        <translation>选中这些块？</translation>
    </message>
    <message>
        <location filename="../src/module/mifare.cpp" line="791"/>
        <source>Failed to read card.</source>
        <translation>读卡失败。</translation>
    </message>
</context>
<context>
    <name>T55xxTab</name>
    <message>
        <location filename="../src/ui/t55xxtab.ui" line="17"/>
        <source>Clone to T55xx</source>
        <translation>复制到T55xx卡</translation>
    </message>
    <message>
        <location filename="../src/ui/t55xxtab.ui" line="25"/>
        <source>Target Type:</source>
        <translation>目标卡片类型：</translation>
    </message>
    <message>
        <location filename="../src/ui/t55xxtab.ui" line="70"/>
        <source>Read</source>
        <translation>读卡</translation>
    </message>
    <message>
        <location filename="../src/ui/t55xxtab.ui" line="80"/>
        <source>Clone</source>
        <translation>复制</translation>
    </message>
</context>
<context>
    <name>Util</name>
    <message>
        <location filename="../src/common/util.cpp" line="122"/>
        <source>Load from external file</source>
        <translation>从外部文件加载</translation>
    </message>
    <message>
        <location filename="../src/common/util.cpp" line="126"/>
        <source>Choose a language:</source>
        <translation>选择语言：</translation>
    </message>
    <message>
        <location filename="../src/common/util.cpp" line="131"/>
        <source>Select the translation file:</source>
        <translation>选择翻译文件：</translation>
    </message>
</context>
</TS>
