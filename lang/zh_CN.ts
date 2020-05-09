<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="zh_CN">
<context>
    <name>MF_Attack_hardnestedDialog</name>
    <message>
        <location filename="../ui/mf_attack_hardnesteddialog.ui" line="14"/>
        <source>Hardnested Attack</source>
        <translation>Hardnested攻击</translation>
    </message>
    <message>
        <source>Known Key:</source>
        <translation type="obsolete">已知Key：</translation>
    </message>
    <message>
        <location filename="../ui/mf_attack_hardnesteddialog.ui" line="20"/>
        <source>Known Block:</source>
        <translation>已知块：</translation>
    </message>
    <message>
        <location filename="../ui/mf_attack_hardnesteddialog.ui" line="29"/>
        <location filename="../ui/mf_attack_hardnesteddialog.ui" line="104"/>
        <source>Block:</source>
        <translation>块：</translation>
    </message>
    <message>
        <location filename="../ui/mf_attack_hardnesteddialog.ui" line="68"/>
        <location filename="../ui/mf_attack_hardnesteddialog.ui" line="143"/>
        <source>A</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_attack_hardnesteddialog.ui" line="73"/>
        <location filename="../ui/mf_attack_hardnesteddialog.ui" line="148"/>
        <source>B</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_attack_hardnesteddialog.ui" line="95"/>
        <source>Target Block:</source>
        <translation>目标块：</translation>
    </message>
    <message>
        <source>Target Block: </source>
        <translation type="vanished">目标块：</translation>
    </message>
</context>
<context>
    <name>MF_Sim_simDialog</name>
    <message>
        <source>Dialog</source>
        <translation type="obsolete">对话框</translation>
    </message>
    <message>
        <location filename="../ui/mf_sim_simdialog.ui" line="14"/>
        <source>Simulate</source>
        <translation>模拟</translation>
    </message>
    <message>
        <location filename="../ui/mf_sim_simdialog.ui" line="37"/>
        <source>u</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_sim_simdialog.ui" line="66"/>
        <source>UID 4 or 7 bytes. If not specified, the UID 4B from emulator memory will be used</source>
        <translation>4或7字节的UID，如果不指定，则使用模拟器内存中的4字节UID</translation>
    </message>
    <message>
        <location filename="../ui/mf_sim_simdialog.ui" line="87"/>
        <source>n</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_sim_simdialog.ui" line="116"/>
        <source>Automatically exit simulation after &lt;numreads&gt; blocks have been read by reader. 0 = infinite</source>
        <translation>在读卡器读取&lt;n&gt;个块后自动退出模拟，n为0或不指定时永远不退出</translation>
    </message>
    <message>
        <location filename="../ui/mf_sim_simdialog.ui" line="137"/>
        <source>i</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_sim_simdialog.ui" line="150"/>
        <source>Interactive, means that console will not be returned until simulation finishes or is aborted</source>
        <translation>交互模式，勾选后PM3客户端将在模拟完成或者模拟中断后才可继续使用</translation>
    </message>
    <message>
        <location filename="../ui/mf_sim_simdialog.ui" line="171"/>
        <source>x</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_sim_simdialog.ui" line="184"/>
        <source>Crack, performs the &apos;reader attack&apos;, nr/ar attack against a legitimate reader, fishes out the key(s)</source>
        <translation>破解，对读卡器进行攻击，通过nr/ar攻击来钓出密码(无卡嗅探)</translation>
    </message>
    <message>
        <location filename="../ui/mf_sim_simdialog.ui" line="205"/>
        <source>e</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_sim_simdialog.ui" line="218"/>
        <source>set keys found from &apos;reader attack&apos; to emulator memory (implies x and i)</source>
        <translation>在获得密码后自动将密码写入模拟器内存（自动勾选x和i）</translation>
    </message>
    <message>
        <location filename="../ui/mf_sim_simdialog.ui" line="239"/>
        <source>f</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_sim_simdialog.ui" line="268"/>
        <source>get UIDs to use for &apos;reader attack&apos; from file &apos;f &lt;filename.txt&gt;&apos; (implies x and i)</source>
        <translation>从&lt;filename.txt&gt;当中获取用于破解读卡器的UID（批量模拟）（自动勾选x和i）</translation>
    </message>
    <message>
        <location filename="../ui/mf_sim_simdialog.ui" line="289"/>
        <source>r</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_sim_simdialog.ui" line="302"/>
        <source>Generate random nonces instead of sequential nonces. Standard reader attack won&apos;t work with this option, only moebius attack works</source>
        <translation>生成随机nonce而不是顺序的nonce，这种情况下PM3将不对读卡器进行标准攻击，只进行moebius攻击</translation>
    </message>
    <message>
        <source> Generate random nonces instead of sequential nonces. Standard reader attack won&apos;t work with this option, only moebius attack works.</source>
        <translation type="vanished">生成随机nonce而不是顺序的nonce，这种情况下PM3将不对读卡器进行标准攻击，只进行moebius攻击</translation>
    </message>
</context>
<context>
    <name>MF_UID_parameterDialog</name>
    <message>
        <source>Dialog</source>
        <translation type="vanished">对话框</translation>
    </message>
    <message>
        <location filename="../ui/mf_uid_parameterdialog.ui" line="14"/>
        <source>Set Parameter</source>
        <translation>设置卡参数</translation>
    </message>
    <message>
        <location filename="../ui/mf_uid_parameterdialog.ui" line="22"/>
        <source>UID:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_uid_parameterdialog.ui" line="32"/>
        <source>ATQA:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_uid_parameterdialog.ui" line="42"/>
        <source>SAK:</source>
        <translation></translation>
    </message>
    <message>
        <source>The parameter will not change if you leave it empty.</source>
        <translation type="vanished">如果留空，则对应参数将保持不变</translation>
    </message>
</context>
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../ui/mainwindow.ui" line="23"/>
        <source>Proxmark3GUI</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="56"/>
        <source>Path:</source>
        <translation>路径：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="80"/>
        <source>Refresh</source>
        <translation>刷新端口</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="87"/>
        <source>Connect</source>
        <translation>连接</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="94"/>
        <source>Disconnect</source>
        <translation>断开</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="110"/>
        <source>Mifare</source>
        <translation>Mifare(IC)卡</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="203"/>
        <source>&gt;&gt;</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="228"/>
        <source>&lt;&lt;</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="260"/>
        <source>F</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="317"/>
        <source>Card Type</source>
        <translation>卡类型</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="332"/>
        <source>MINI</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="339"/>
        <source>1K</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="349"/>
        <source>2K</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="356"/>
        <source>4K</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="366"/>
        <source>File</source>
        <translation>文件</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="384"/>
        <location filename="../ui/mainwindow.ui" line="948"/>
        <source>Load</source>
        <translation>加载</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="397"/>
        <location filename="../ui/mainwindow.ui" line="961"/>
        <source>Save</source>
        <translation>保存</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="417"/>
        <location filename="../ui/mainwindow.cpp" line="602"/>
        <source>Data</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="427"/>
        <source>Key</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="437"/>
        <source>Attack</source>
        <translation>破解</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="462"/>
        <source>Card Info</source>
        <translation>读卡片信息</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="475"/>
        <source>Check Default</source>
        <translation>验证默认密码</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="488"/>
        <source>Nested</source>
        <translation>Nested攻击</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="495"/>
        <source>Hardnested</source>
        <translation>Hardested攻击</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="520"/>
        <source>Read/Write</source>
        <translation>读/写</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="530"/>
        <source>Block:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="562"/>
        <source>Key:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="581"/>
        <source>Key Type:</source>
        <translation>Key类型：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="601"/>
        <source>A</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="606"/>
        <source>B</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="614"/>
        <source>Data:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="636"/>
        <source>Normal(Require Password)</source>
        <translation>普通卡（需要密码）</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="651"/>
        <location filename="../ui/mainwindow.ui" line="740"/>
        <source>Read Block</source>
        <translation>读单个块</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="658"/>
        <location filename="../ui/mainwindow.ui" line="747"/>
        <source>Write Block</source>
        <translation>写单个块</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="665"/>
        <location filename="../ui/mainwindow.ui" line="754"/>
        <location filename="../ui/mainwindow.ui" line="854"/>
        <source>Read All</source>
        <translation>读所有块</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="672"/>
        <location filename="../ui/mainwindow.ui" line="761"/>
        <source>Write All</source>
        <translation>写所有块</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="691"/>
        <source>Dump</source>
        <translation>Dump命令</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="704"/>
        <source>Restore</source>
        <translation>Restore命令</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="714"/>
        <source>Chinese Magic Card(Without Password)</source>
        <translation>UID卡（不需要密码）</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="726"/>
        <source>Lock UFUID Card</source>
        <translation>锁定UFUID卡</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="733"/>
        <location filename="../ui/mainwindow.cpp" line="461"/>
        <source>About UID Card</source>
        <translation>关于UID卡</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="774"/>
        <source>Set Parameter</source>
        <translation>设置卡参数</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="793"/>
        <source>Wipe</source>
        <translation>擦除</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="819"/>
        <location filename="../ui/mainwindow.ui" line="874"/>
        <source>Simulate</source>
        <translation>模拟</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="847"/>
        <source>Load from data above</source>
        <translation>从上方数据导入</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="410"/>
        <location filename="../ui/mainwindow.ui" line="867"/>
        <source>Clear</source>
        <translation>清空</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="897"/>
        <location filename="../ui/mainwindow.ui" line="928"/>
        <source>Sniff</source>
        <translation>嗅探</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="935"/>
        <source>List Sniff Data</source>
        <translation>列出嗅探数据</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="987"/>
        <source>RawCommand</source>
        <translation>原始命令</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1034"/>
        <location filename="../ui/mainwindow.cpp" line="143"/>
        <source>History:</source>
        <translation>命令历史：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1066"/>
        <source>ClearHistory</source>
        <translation>清空历史</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1085"/>
        <source>Send</source>
        <translation>发送</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1092"/>
        <source>ClearOutput</source>
        <translation>清空输出</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="77"/>
        <location filename="../ui/mainwindow.cpp" line="179"/>
        <location filename="../ui/mainwindow.cpp" line="229"/>
        <location filename="../ui/mainwindow.cpp" line="246"/>
        <location filename="../ui/mainwindow.cpp" line="259"/>
        <location filename="../ui/mainwindow.cpp" line="278"/>
        <location filename="../ui/mainwindow.cpp" line="291"/>
        <location filename="../ui/mainwindow.cpp" line="314"/>
        <location filename="../ui/mainwindow.cpp" line="327"/>
        <location filename="../ui/mainwindow.cpp" line="518"/>
        <location filename="../ui/mainwindow.cpp" line="537"/>
        <source>Info</source>
        <translation>信息</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="77"/>
        <source>Plz choose a port first</source>
        <translation>请先选择端口</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="91"/>
        <source>Connected</source>
        <translation>已连接</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="95"/>
        <location filename="../ui/mainwindow.cpp" line="105"/>
        <location filename="../ui/mainwindow.cpp" line="592"/>
        <source>Not Connected</source>
        <translation>未连接</translation>
    </message>
    <message>
        <source>When Changeing card type, the data and keys in this app will be cleard.
Continue?</source>
        <translation type="vanished">更改卡容量后，窗口中的data和key会被清空\n要继续吗？</translation>
    </message>
    <message>
        <source>Plz choose the data file:</source>
        <translation type="vanished">请选择data文件：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="272"/>
        <source>Binary Data Files(*.bin *.dump);;Text Data Files(*.txt *.eml);;All Files(*.*)</source>
        <translation>二进制Data文件(*.bin *.dump);;文本Data文件(*.txt *.eml);;所有文件(*.*)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="278"/>
        <location filename="../ui/mainwindow.cpp" line="291"/>
        <location filename="../ui/mainwindow.cpp" line="518"/>
        <source>Failed to open</source>
        <translation>无法打开</translation>
    </message>
    <message>
        <source>Plz choose the key file:</source>
        <translation type="vanished">请选择key文件：</translation>
    </message>
    <message>
        <source>Binary Key Files(*.bin *.dump);;All Files(*.*)</source>
        <translation type="vanished">二进制Key文件(*.bin *.dump);;所有文件(*.*)</translation>
    </message>
    <message>
        <source>Save data to</source>
        <translation type="vanished">保存数据至</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="179"/>
        <source>When Changeing card type, the data and keys in this app will be cleard.</source>
        <translation>卡片容量改变后，上方的所有Data和Key会被清空。</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="179"/>
        <source>Continue?</source>
        <translation>确定？</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="208"/>
        <source>Plz select the font of data widget and key widget</source>
        <translation>请选择Data窗口和Key窗口的字体</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="229"/>
        <source>Data must consists of 32 Hex symbols(Whitespace is allowed)</source>
        <translation>Data必须由32个十六进制字符组成（中间可含有空格）</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="246"/>
        <location filename="../ui/mainwindow.cpp" line="259"/>
        <source>Key must consists of 12 Hex symbols(Whitespace is allowed)</source>
        <translation>Key必须由12个十六进制字符组成（中间可含有空格）</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="271"/>
        <source>Plz select the data file:</source>
        <translation>请选择data文件：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="284"/>
        <source>Plz select the key file:</source>
        <translation>请选择key文件：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="285"/>
        <source>Binary Key Files(*.bin *.dump);;Binary Data Files(*.bin *.dump);;All Files(*.*)</source>
        <translation>二进制Key文件(*.bin *.dump)二进制Data文件(*.bin *.dump);;所有文件(*.*)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="307"/>
        <source>Plz select the location to save data file:</source>
        <translation>请选择文件保存的位置：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="308"/>
        <source>Binary Data Files(*.bin *.dump);;Text Data Files(*.txt *.eml)</source>
        <translation>二进制Data文件(*.bin *.dump);;文本Data文件(*.txt *.eml)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="314"/>
        <location filename="../ui/mainwindow.cpp" line="327"/>
        <location filename="../ui/mainwindow.cpp" line="537"/>
        <source>Failed to save to</source>
        <translation>无法保存至</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="320"/>
        <source>Plz select the location to save key file:</source>
        <translation>请选择key文件保存的位置：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="321"/>
        <source>Binary Key Files(*.bin *.dump)</source>
        <translation>二进制Key文件(*.bin *.dump)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="446"/>
        <source>    Normally, the Block 0 of a typical Mifare card, which contains the UID, is locked during the manufacture. Users cannot write anything to Block 0 or set a new UID to a normal Mifare card.</source>
        <translation>    普通Mifare卡的Block0无法写入，UID也不能更改</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="447"/>
        <source>    Chinese Magic Cards(aka UID Cards) are some special cards whose Block 0 are writeable. And you can change UID by writing to it.</source>
        <translation>    UID卡（在国外叫Chinese Magic Card）的Block0可写，UID可变</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="449"/>
        <source>There are two versions of Chinese Magic Cards, the Gen1 and the Gen2.</source>
        <translation>国外把UID卡分为Chinese Magic Card Gen1和Gen2</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="450"/>
        <source>    Gen1:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="450"/>
        <source>    also called UID card in China. It responses to some backdoor commands so you can access any blocks without password. The Proxmark3 has a bunch of related commands(csetblk, cgetblk, ...) to deal with this type of card, and my GUI also support these commands.</source>
        <translation>    指通常所说的UID卡，可以通过后门指令直接读写块而无需密码，在PM3和此GUI中有特殊命令处理这类卡片</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="451"/>
        <source>    Gen2:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="451"/>
        <source>    doesn&apos;t response to the backdoor commands, which means that a reader cannot detect whether it is a Chinese Magic Card or not by sending backdoor commands.</source>
        <translation>    这个叫法在国内比较罕见，在国外指CUID/FUID/UFUID这类对后门指令不响应的卡（防火墙卡）</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="453"/>
        <source>There are some types of Chinese Magic Card Gen2.</source>
        <translation>以下是Gen2卡的详细介绍</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="454"/>
        <source>    CUID Card:</source>
        <translation>    CUID卡：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="454"/>
        <source>    the Block 0 is writeable, you can write to this block repeatedly by normal wrbl command.</source>
        <translation>    可通过普通的写块命令来写Block0，可重复擦写</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="455"/>
        <source>    (hf mf wrbl 0 A FFFFFFFFFFFF &lt;the data you want to write&gt;)</source>
        <translation>    (hf mf wrbl 0 A FFFFFFFFFFFF &lt;待写入数据&gt;)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="456"/>
        <source>    FUID Card:</source>
        <translation>    FUID卡：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="456"/>
        <source>    you can only write to Block 0 once. After that, it seems like a typical Mifare card(Block 0 cannot be written to).</source>
        <translation>    Block0只能写入一次</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="457"/>
        <source>    (some readers might try changing the Block 0, which could detect the CUID Card. In that case, you should use FUID card.)</source>
        <translation>    (更高级的穿防火墙卡，可以过一些能识别出CUID卡的读卡器)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="458"/>
        <source>    UFUID Card:</source>
        <translation>    UFUID卡：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="458"/>
        <source>    It behaves like a CUID card(or UID card? I&apos;m not sure) before you send some special command to lock it. Once it is locked, you cannot change its Block 0(just like a typical Mifare card).</source>
        <translation>    锁卡前和普通UID/CUID卡一样可以反复读写Block0，用特殊命令锁卡后就和FUID卡一样了</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="460"/>
        <source>    Seemingly, these Chinese Magic Cards are more easily to be compromised by Nested Attack(it takes little time to get an unknown key).</source>
        <translation>    所有UID卡都似乎更容易被Nested攻击破解</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="505"/>
        <source>Plz select the trace file:</source>
        <translation>请选择trace文件：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="506"/>
        <source>Trace Files(*.trc);;All Files(*.*)</source>
        <translation>Trace文件(*.trc);;所有文件(*.*)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="528"/>
        <source>Plz select the location to save trace file:</source>
        <translation>请选择trace文件保存的位置：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="529"/>
        <source>Trace Files(*.trc)</source>
        <translation>Trace文件(*.trc)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="593"/>
        <location filename="../ui/mainwindow.cpp" line="710"/>
        <source>Idle</source>
        <translation>空闲</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="600"/>
        <location filename="../ui/mainwindow.cpp" line="609"/>
        <source>Sec</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="601"/>
        <source>Blk</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="610"/>
        <source>KeyA</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="611"/>
        <source>KeyB</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="647"/>
        <source>HW Version:</source>
        <translation>固件版本：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="649"/>
        <source>PM3:</source>
        <translation>连接状态：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="651"/>
        <source>State:</source>
        <translation>运行状态：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="706"/>
        <source>Running</source>
        <translation>运行中</translation>
    </message>
</context>
<context>
    <name>Mifare</name>
    <message>
        <source>info</source>
        <translation type="vanished">信息：</translation>
    </message>
    <message>
        <location filename="../module/mifare.cpp" line="310"/>
        <location filename="../module/mifare.cpp" line="419"/>
        <source>Success!</source>
        <translation>成功！</translation>
    </message>
    <message>
        <location filename="../module/mifare.cpp" line="310"/>
        <location filename="../module/mifare.cpp" line="314"/>
        <location filename="../module/mifare.cpp" line="419"/>
        <location filename="../module/mifare.cpp" line="423"/>
        <location filename="../module/mifare.cpp" line="473"/>
        <source>Info</source>
        <translation>信息</translation>
    </message>
    <message>
        <location filename="../module/mifare.cpp" line="314"/>
        <location filename="../module/mifare.cpp" line="423"/>
        <source>Failed!</source>
        <translation>失败！</translation>
    </message>
    <message>
        <location filename="../module/mifare.cpp" line="473"/>
        <source>Failed to read card.</source>
        <translation>读卡失败。</translation>
    </message>
</context>
</TS>
