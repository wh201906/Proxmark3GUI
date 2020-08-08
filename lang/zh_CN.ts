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
</context>
<context>
    <name>MF_Sim_simDialog</name>
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
</context>
<context>
    <name>MF_UID_parameterDialog</name>
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
</context>
<context>
    <name>MF_trailerDecoderDialog</name>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="14"/>
        <source>Trailer Decoder</source>
        <translation>Trailer解码</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="22"/>
        <source>Blocks</source>
        <translation>块大小</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="28"/>
        <source>4</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="38"/>
        <source>16</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="67"/>
        <source>Trailer Data:
(like &quot;FF0780&quot; or &quot;FF 07 80&quot;)</source>
        <translation>输入Access Bits
（形如“FF0780”或“FF 07 80”）</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="120"/>
        <source>Or set bits manually</source>
        <translation>手动设置访问情况：</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="134"/>
        <source>Cx0</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="155"/>
        <source>Cx1</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="176"/>
        <source>Cx2</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="197"/>
        <source>Cx3</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="235"/>
        <source>Data Block Permission:</source>
        <translation>数据Block访问权限：</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="252"/>
        <source>Block0</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="257"/>
        <source>Block1</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="262"/>
        <source>Block2</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="267"/>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="307"/>
        <source>Read</source>
        <translation>读</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="272"/>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="312"/>
        <source>Write</source>
        <translation>写</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="277"/>
        <source>Increase</source>
        <translation>增加</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="282"/>
        <source>Decrease/Transfer/Restore</source>
        <translation>减少/从缓冲区写入/读入至缓冲区</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="290"/>
        <source>Trailer Block Permission:</source>
        <translation>Trailer访问权限：</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="317"/>
        <source>KeyA</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="322"/>
        <source>Access Bits</source>
        <translation>Access Bits</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="327"/>
        <source>KeyB</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="337"/>
        <source>Reference:
MF1S70YYX_V1 Product data sheet
Rev. 3.2 — 23 November 2017</source>
        <translation>参考资料：
MF1S70YYX_V1 Product data sheet
Rev. 3.2 — 23 November 2017</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="358"/>
        <source>Note:the Access Bits usually contains 4 bytes(8 hex symbols), but only the first 3 bytes matters. You can set the 4th byte randomly.</source>
        <translation>注意：Access Bits一般包含4个字节（8个16进制字符），但只有前3个字节决定访问情况，最后一个字节可任意设置。</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.cpp" line="43"/>
        <source>Invalid!
It could make the whole sector blocked irreversibly!</source>
        <translation>无效！
可能导致整个扇区被不可逆转地锁定！</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.cpp" line="52"/>
        <source>Valid</source>
        <translation>有效</translation>
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
        <location filename="../ui/mainwindow.ui" line="76"/>
        <source>Refresh</source>
        <translation>刷新端口</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="83"/>
        <source>Connect</source>
        <translation>连接</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="90"/>
        <source>Disconnect</source>
        <translation>断开</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="109"/>
        <source>Mifare</source>
        <translation>Mifare(IC)卡</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="279"/>
        <source>Card Type</source>
        <translation>卡类型</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="294"/>
        <source>MINI</source>
        <extracomment>320</extracomment>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="301"/>
        <source>1K</source>
        <extracomment>1024</extracomment>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="311"/>
        <source>2K</source>
        <extracomment>2048</extracomment>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="318"/>
        <source>4K</source>
        <extracomment>4096</extracomment>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="328"/>
        <source>File</source>
        <translation>文件</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="349"/>
        <location filename="../ui/mainwindow.ui" line="952"/>
        <source>Load</source>
        <translation>加载</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="362"/>
        <location filename="../ui/mainwindow.ui" line="965"/>
        <source>Save</source>
        <translation>保存</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="382"/>
        <location filename="../ui/mainwindow.cpp" line="751"/>
        <source>Data</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="392"/>
        <source>Key</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="402"/>
        <source>Attack</source>
        <translation>破解</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="430"/>
        <source>Card Info</source>
        <translation>读卡片信息</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="443"/>
        <source>Check Default</source>
        <translation>验证默认密码</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="456"/>
        <source>Nested</source>
        <translation>Nested攻击</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="463"/>
        <source>Hardnested</source>
        <translation>Hardested攻击</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="488"/>
        <source>Read/Write</source>
        <translation>读/写</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="501"/>
        <source>Block:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="533"/>
        <source>Key:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="552"/>
        <source>Key Type:</source>
        <translation>Key类型：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="926"/>
        <source>Snoop</source>
        <translation>嗅探(Snoop)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="939"/>
        <source>List Data</source>
        <translation>列出嗅探数据</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="575"/>
        <source>Data:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="597"/>
        <source>Normal(Require Password)</source>
        <translation>普通卡（需要密码）</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="830"/>
        <source>Read All</source>
        <translation>读所有块</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="655"/>
        <source>Dump</source>
        <translation>Dump命令</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="668"/>
        <source>Restore</source>
        <translation>Restore命令</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="678"/>
        <source>Chinese Magic Card(Without Password)</source>
        <translation>UID卡（不需要密码）</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="693"/>
        <source>Lock UFUID Card</source>
        <translation>锁定UFUID卡</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="700"/>
        <location filename="../ui/mainwindow.cpp" line="592"/>
        <source>About UID Card</source>
        <translation>关于UID卡</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="741"/>
        <source>Set Parameter</source>
        <translation>设置卡参数</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="760"/>
        <source>Wipe</source>
        <translation>擦除</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="786"/>
        <location filename="../ui/mainwindow.ui" line="856"/>
        <source>Simulate</source>
        <translation>模拟</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="817"/>
        <source>Load from data above</source>
        <translation>从上方数据导入</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="375"/>
        <location filename="../ui/mainwindow.ui" line="843"/>
        <source>Clear</source>
        <translation>清空</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="184"/>
        <source>Select All</source>
        <translation>全选</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="194"/>
        <source>KeyBlocks-&gt;Key</source>
        <translation>密码区-&gt;密码</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="201"/>
        <source>KeyBlocks&lt;-Key</source>
        <translation>密码区&lt;-密码</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="208"/>
        <source>Fill Keys</source>
        <translation>填充密码</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="215"/>
        <source>Trailer Decoder</source>
        <translation>Trailer解码</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="222"/>
        <source>Set Fonts</source>
        <translation>设置字体</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="615"/>
        <location filename="../ui/mainwindow.ui" line="707"/>
        <source>Read One</source>
        <translation>读取单个区</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="622"/>
        <location filename="../ui/mainwindow.ui" line="714"/>
        <source>Write One</source>
        <translation>写入单个区</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="629"/>
        <location filename="../ui/mainwindow.ui" line="721"/>
        <source>Read Selected</source>
        <translation>读取选中块</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="636"/>
        <location filename="../ui/mainwindow.ui" line="728"/>
        <source>Write Selected</source>
        <translation>写入选中块</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="879"/>
        <location filename="../ui/mainwindow.ui" line="913"/>
        <source>Sniff</source>
        <translation>嗅探</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="991"/>
        <source>RawCommand</source>
        <translation>原始命令</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1038"/>
        <location filename="../ui/mainwindow.cpp" line="145"/>
        <source>History:</source>
        <translation>命令历史：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1070"/>
        <source>ClearHistory</source>
        <translation>清空历史</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1089"/>
        <source>Send</source>
        <translation>发送</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1096"/>
        <source>ClearOutput</source>
        <translation>清空输出</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="77"/>
        <location filename="../ui/mainwindow.cpp" line="184"/>
        <location filename="../ui/mainwindow.cpp" line="346"/>
        <location filename="../ui/mainwindow.cpp" line="365"/>
        <location filename="../ui/mainwindow.cpp" line="378"/>
        <location filename="../ui/mainwindow.cpp" line="397"/>
        <location filename="../ui/mainwindow.cpp" line="410"/>
        <location filename="../ui/mainwindow.cpp" line="433"/>
        <location filename="../ui/mainwindow.cpp" line="446"/>
        <location filename="../ui/mainwindow.cpp" line="649"/>
        <location filename="../ui/mainwindow.cpp" line="668"/>
        <source>Info</source>
        <translation>信息</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="77"/>
        <source>Plz choose a port first</source>
        <translation>请先选择端口</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="92"/>
        <source>Connected</source>
        <translation>已连接</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="97"/>
        <location filename="../ui/mainwindow.cpp" line="107"/>
        <location filename="../ui/mainwindow.cpp" line="741"/>
        <source>Not Connected</source>
        <translation>未连接</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="391"/>
        <source>Binary Data Files(*.bin *.dump);;Text Data Files(*.txt *.eml);;All Files(*.*)</source>
        <translation>二进制Data文件(*.bin *.dump);;文本Data文件(*.txt *.eml);;所有文件(*.*)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="397"/>
        <location filename="../ui/mainwindow.cpp" line="410"/>
        <location filename="../ui/mainwindow.cpp" line="649"/>
        <source>Failed to open</source>
        <translation>无法打开</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="184"/>
        <source>Continue?</source>
        <translation>确定？</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="184"/>
        <source>Some of the data and key will be cleared.</source>
        <translation>部分数据和密码将被清除</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="252"/>
        <source>Plz select the font of data widget and key widget</source>
        <translation>请选择Data窗口和Key窗口的字体</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="346"/>
        <source>Data must consists of 32 Hex symbols(Whitespace is allowed)</source>
        <translation>Data必须由32个十六进制字符组成（中间可含有空格）</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="365"/>
        <location filename="../ui/mainwindow.cpp" line="378"/>
        <source>Key must consists of 12 Hex symbols(Whitespace is allowed)</source>
        <translation>Key必须由12个十六进制字符组成（中间可含有空格）</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="390"/>
        <source>Plz select the data file:</source>
        <translation>请选择data文件：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="403"/>
        <source>Plz select the key file:</source>
        <translation>请选择key文件：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="404"/>
        <source>Binary Key Files(*.bin *.dump);;Binary Data Files(*.bin *.dump);;All Files(*.*)</source>
        <translation>二进制Key文件(*.bin *.dump)二进制Data文件(*.bin *.dump);;所有文件(*.*)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="426"/>
        <source>Plz select the location to save data file:</source>
        <translation>请选择文件保存的位置：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="427"/>
        <source>Binary Data Files(*.bin *.dump);;Text Data Files(*.txt *.eml)</source>
        <translation>二进制Data文件(*.bin *.dump);;文本Data文件(*.txt *.eml)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="433"/>
        <location filename="../ui/mainwindow.cpp" line="446"/>
        <location filename="../ui/mainwindow.cpp" line="668"/>
        <source>Failed to save to</source>
        <translation>无法保存至</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="439"/>
        <source>Plz select the location to save key file:</source>
        <translation>请选择key文件保存的位置：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="440"/>
        <source>Binary Key Files(*.bin *.dump)</source>
        <translation>二进制Key文件(*.bin *.dump)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="577"/>
        <source>    Normally, the Block 0 of a typical Mifare card, which contains the UID, is locked during the manufacture. Users cannot write anything to Block 0 or set a new UID to a normal Mifare card.</source>
        <translation>    普通Mifare卡的Block0无法写入，UID也不能更改</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="578"/>
        <source>    Chinese Magic Cards(aka UID Cards) are some special cards whose Block 0 are writeable. And you can change UID by writing to it.</source>
        <translation>    UID卡（在国外叫Chinese Magic Card）的Block0可写，UID可变</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="580"/>
        <source>There are two versions of Chinese Magic Cards, the Gen1 and the Gen2.</source>
        <translation>国外把UID卡分为Chinese Magic Card Gen1和Gen2</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="581"/>
        <source>    Gen1:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="581"/>
        <source>    also called UID card in China. It responses to some backdoor commands so you can access any blocks without password. The Proxmark3 has a bunch of related commands(csetblk, cgetblk, ...) to deal with this type of card, and my GUI also support these commands.</source>
        <translation>    指通常所说的UID卡，可以通过后门指令直接读写块而无需密码，在PM3和此GUI中有特殊命令处理这类卡片</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="582"/>
        <source>    Gen2:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="582"/>
        <source>    doesn&apos;t response to the backdoor commands, which means that a reader cannot detect whether it is a Chinese Magic Card or not by sending backdoor commands.</source>
        <translation>    这个叫法在国内比较罕见，在国外指CUID/FUID/UFUID这类对后门指令不响应的卡（防火墙卡）</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="584"/>
        <source>There are some types of Chinese Magic Card Gen2.</source>
        <translation>以下是Gen2卡的详细介绍</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="585"/>
        <source>    CUID Card:</source>
        <translation>    CUID卡：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="585"/>
        <source>    the Block 0 is writeable, you can write to this block repeatedly by normal wrbl command.</source>
        <translation>    可通过普通的写块命令来写Block0，可重复擦写</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="586"/>
        <source>    (hf mf wrbl 0 A FFFFFFFFFFFF &lt;the data you want to write&gt;)</source>
        <translation>    (hf mf wrbl 0 A FFFFFFFFFFFF &lt;待写入数据&gt;)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="587"/>
        <source>    FUID Card:</source>
        <translation>    FUID卡：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="587"/>
        <source>    you can only write to Block 0 once. After that, it seems like a typical Mifare card(Block 0 cannot be written to).</source>
        <translation>    Block0只能写入一次</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="588"/>
        <source>    (some readers might try changing the Block 0, which could detect the CUID Card. In that case, you should use FUID card.)</source>
        <translation>    (更高级的穿防火墙卡，可以过一些能识别出CUID卡的读卡器)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="589"/>
        <source>    UFUID Card:</source>
        <translation>    UFUID卡：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="589"/>
        <source>    It behaves like a CUID card(or UID card? I&apos;m not sure) before you send some special command to lock it. Once it is locked, you cannot change its Block 0(just like a typical Mifare card).</source>
        <translation>    锁卡前和普通UID/CUID卡一样可以反复读写Block0，用特殊命令锁卡后就和FUID卡一样了</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="591"/>
        <source>    Seemingly, these Chinese Magic Cards are more easily to be compromised by Nested Attack(it takes little time to get an unknown key).</source>
        <translation>    所有UID卡都似乎更容易被Nested攻击破解</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="636"/>
        <source>Plz select the trace file:</source>
        <translation>请选择trace文件：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="637"/>
        <source>Trace Files(*.trc);;All Files(*.*)</source>
        <translation>Trace文件(*.trc);;所有文件(*.*)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="659"/>
        <source>Plz select the location to save trace file:</source>
        <translation>请选择trace文件保存的位置：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="660"/>
        <source>Trace Files(*.trc)</source>
        <translation>Trace文件(*.trc)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="742"/>
        <location filename="../ui/mainwindow.cpp" line="897"/>
        <source>Idle</source>
        <translation>空闲</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="749"/>
        <location filename="../ui/mainwindow.cpp" line="758"/>
        <source>Sec</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="750"/>
        <source>Blk</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="759"/>
        <source>KeyA</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="760"/>
        <source>KeyB</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="834"/>
        <source>HW Version:</source>
        <translation>固件版本：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="836"/>
        <source>PM3:</source>
        <translation>连接状态：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="838"/>
        <source>State:</source>
        <translation>运行状态：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="893"/>
        <source>Running</source>
        <translation>运行中</translation>
    </message>
</context>
<context>
    <name>Mifare</name>
    <message>
        <location filename="../module/mifare.cpp" line="524"/>
        <location filename="../module/mifare.cpp" line="611"/>
        <source>Success!</source>
        <translation>成功！</translation>
    </message>
    <message>
        <location filename="../module/mifare.cpp" line="219"/>
        <location filename="../module/mifare.cpp" line="524"/>
        <location filename="../module/mifare.cpp" line="528"/>
        <location filename="../module/mifare.cpp" line="611"/>
        <location filename="../module/mifare.cpp" line="615"/>
        <location filename="../module/mifare.cpp" line="665"/>
        <source>Info</source>
        <translation>信息</translation>
    </message>
    <message>
        <location filename="../module/mifare.cpp" line="219"/>
        <source>Plz provide at least one known key</source>
        <translation>请至少提供一个已知密码</translation>
    </message>
    <message>
        <location filename="../module/mifare.cpp" line="411"/>
        <location filename="../module/mifare.cpp" line="528"/>
        <location filename="../module/mifare.cpp" line="615"/>
        <source>Failed!</source>
        <translation>失败！</translation>
    </message>
    <message>
        <location filename="../module/mifare.cpp" line="665"/>
        <source>Failed to read card.</source>
        <translation>读卡失败。</translation>
    </message>
</context>
</TS>
