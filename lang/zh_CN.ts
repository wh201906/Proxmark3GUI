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
        <translation>卡号：</translation>
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
        <translation>输入控制位数据
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
        <translation>块数据访问权限：</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="252"/>
        <source>Block0</source>
        <translation>块0</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="257"/>
        <source>Block1</source>
        <translation>块1</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="262"/>
        <source>Block2</source>
        <translation>块2</translation>
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
        <translation>A密钥</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="322"/>
        <source>Access Bits</source>
        <translation>控制位</translation>
    </message>
    <message>
        <location filename="../ui/mf_trailerdecoderdialog.ui" line="327"/>
        <source>KeyB</source>
        <translation>B密钥</translation>
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
        <location filename="../ui/mainwindow.ui" line="82"/>
        <source>Refresh</source>
        <translation>刷新端口</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="95"/>
        <source>Connect</source>
        <translation>连接</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="108"/>
        <source>Disconnect</source>
        <translation>断开</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="127"/>
        <source>Mifare</source>
        <translation>Mifare(IC)卡</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="209"/>
        <source>Select Trailer</source>
        <translation>选中密码块</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="347"/>
        <source>Card Type</source>
        <translation>卡片类型</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="368"/>
        <source>MINI</source>
        <extracomment>320</extracomment>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="381"/>
        <source>1K</source>
        <extracomment>1024</extracomment>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="397"/>
        <source>2K</source>
        <extracomment>2048</extracomment>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="410"/>
        <source>4K</source>
        <extracomment>4096</extracomment>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="420"/>
        <source>File</source>
        <translation>文件</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="441"/>
        <location filename="../ui/mainwindow.ui" line="1134"/>
        <source>Load</source>
        <translation>加载</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="454"/>
        <location filename="../ui/mainwindow.ui" line="1147"/>
        <source>Save</source>
        <translation>保存</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="474"/>
        <location filename="../ui/mainwindow.cpp" line="814"/>
        <source>Data</source>
        <translation>数据</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="484"/>
        <source>Key</source>
        <translation>密钥</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="494"/>
        <source>Attack</source>
        <translation>破解</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="528"/>
        <source>Card Info</source>
        <translation>读卡信息</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="541"/>
        <source>Check Default</source>
        <translation>验证默认密码</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="554"/>
        <source>Nested</source>
        <translation>Nested攻击</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="567"/>
        <source>Hardnested</source>
        <translation>Hardested攻击</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="592"/>
        <source>Read/Write</source>
        <translation>读/写</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="605"/>
        <source>Block:</source>
        <translation>块：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="637"/>
        <source>Key:</source>
        <translation>密钥：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="656"/>
        <source>Key Type:</source>
        <translation>密钥类型：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1108"/>
        <source>Snoop</source>
        <translation>嗅探(Snoop)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1121"/>
        <source>List Data</source>
        <translation>列出嗅探数据</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="679"/>
        <source>Data:</source>
        <translation>数据：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="701"/>
        <source>Normal(Require Password)</source>
        <translation>普通卡（需要密码）</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="783"/>
        <source>Dump</source>
        <translation>导出Dump</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="802"/>
        <source>Restore</source>
        <translation>一键写卡</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="812"/>
        <source>Chinese Magic Card(Without Password)</source>
        <translation>UID卡（不需要密码）</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="833"/>
        <source>Lock UFUID Card</source>
        <translation>锁定UFUID卡</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="846"/>
        <location filename="../ui/mainwindow.cpp" line="651"/>
        <source>About UID Card</source>
        <translation>关于UID卡</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="917"/>
        <source>Set Parameter</source>
        <translation>设置卡参数</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="936"/>
        <source>Wipe</source>
        <translation>清除</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="962"/>
        <location filename="../ui/mainwindow.ui" line="1038"/>
        <source>Simulate</source>
        <translation>模拟</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="467"/>
        <location filename="../ui/mainwindow.ui" line="1025"/>
        <source>Clear</source>
        <translation>清空</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="202"/>
        <source>Select All</source>
        <translation>全选</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="238"/>
        <source>KeyBlocks-&gt;Key</source>
        <translation>密码区-&gt;密码</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="251"/>
        <source>KeyBlocks&lt;-Key</source>
        <translation>密码区&lt;-密码</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="264"/>
        <source>Fill Keys</source>
        <translation>填充密码</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="277"/>
        <source>Trailer Decoder</source>
        <translation>Trailer解码</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="290"/>
        <source>Set Fonts</source>
        <translation>设置字体</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="725"/>
        <location filename="../ui/mainwindow.ui" line="859"/>
        <source>Read One</source>
        <translation>读取单个区</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="738"/>
        <location filename="../ui/mainwindow.ui" line="872"/>
        <source>Write One</source>
        <translation>写入单个区</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="751"/>
        <location filename="../ui/mainwindow.ui" line="885"/>
        <location filename="../ui/mainwindow.ui" line="1012"/>
        <source>Read Selected</source>
        <translation>读取选中块</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="764"/>
        <location filename="../ui/mainwindow.ui" line="898"/>
        <location filename="../ui/mainwindow.ui" line="999"/>
        <source>Write Selected</source>
        <translation>写入选中块</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1061"/>
        <location filename="../ui/mainwindow.ui" line="1095"/>
        <source>Sniff</source>
        <translation>嗅探</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1173"/>
        <source>RawCommand</source>
        <translation>原始命令</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1220"/>
        <location filename="../ui/mainwindow.cpp" line="149"/>
        <source>History:</source>
        <translation>命令历史：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1252"/>
        <source>ClearHistory</source>
        <translation>清空历史</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1271"/>
        <source>Send</source>
        <translation>发送</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.ui" line="1278"/>
        <source>ClearOutput</source>
        <translation>清空输出</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="81"/>
        <location filename="../ui/mainwindow.cpp" line="188"/>
        <location filename="../ui/mainwindow.cpp" line="414"/>
        <location filename="../ui/mainwindow.cpp" line="434"/>
        <location filename="../ui/mainwindow.cpp" line="447"/>
        <location filename="../ui/mainwindow.cpp" line="466"/>
        <location filename="../ui/mainwindow.cpp" line="479"/>
        <location filename="../ui/mainwindow.cpp" line="502"/>
        <location filename="../ui/mainwindow.cpp" line="515"/>
        <location filename="../ui/mainwindow.cpp" line="709"/>
        <location filename="../ui/mainwindow.cpp" line="728"/>
        <source>Info</source>
        <translation>信息</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="81"/>
        <source>Plz choose a port first</source>
        <translation>请先选择端口</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="96"/>
        <source>Connected</source>
        <translation>已连接</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="101"/>
        <location filename="../ui/mainwindow.cpp" line="111"/>
        <location filename="../ui/mainwindow.cpp" line="804"/>
        <source>Not Connected</source>
        <translation>未连接</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="460"/>
        <source>Binary Data Files(*.bin *.dump);;Text Data Files(*.txt *.eml);;All Files(*.*)</source>
        <translation>二进制数据文件(*.bin *.dump);;文本数据文件(*.txt *.eml);;所有文件(*.*)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="466"/>
        <location filename="../ui/mainwindow.cpp" line="479"/>
        <location filename="../ui/mainwindow.cpp" line="709"/>
        <source>Failed to open</source>
        <translation>无法打开</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="188"/>
        <source>Continue?</source>
        <translation>确定？</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="10"/>
        <source>Check Update</source>
        <translation>检查更新</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="188"/>
        <source>Some of the data and key will be cleared.</source>
        <translation>部分数据和密码将被清除</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="301"/>
        <source>Plz select the font of data widget and key widget</source>
        <translation>请选择数据窗口和密钥窗口的字体</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="414"/>
        <source>Data must consists of 32 Hex symbols(Whitespace is allowed)</source>
        <translation>数据必须由32个十六进制字符组成（中间可含有空格）</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="434"/>
        <location filename="../ui/mainwindow.cpp" line="447"/>
        <source>Key must consists of 12 Hex symbols(Whitespace is allowed)</source>
        <translation>密钥必须由12个十六进制字符组成（中间可含有空格）</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="459"/>
        <source>Plz select the data file:</source>
        <translation>请选择数据文件：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="472"/>
        <source>Plz select the key file:</source>
        <translation>请选择密钥文件：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="473"/>
        <source>Binary Key Files(*.bin *.dump);;Binary Data Files(*.bin *.dump);;All Files(*.*)</source>
        <translation>二进制密钥文件(*.bin *.dump)二进制密钥文件(*.bin *.dump);所有文件(*.*)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="495"/>
        <source>Plz select the location to save data file:</source>
        <translation>请选择数据文件保存的位置：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="496"/>
        <source>Binary Data Files(*.bin *.dump);;Text Data Files(*.txt *.eml)</source>
        <translation>二进制数据文件(*.bin *.dump);文本数据文件(*.txt *.eml)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="502"/>
        <location filename="../ui/mainwindow.cpp" line="515"/>
        <location filename="../ui/mainwindow.cpp" line="728"/>
        <source>Failed to save to</source>
        <translation>无法保存至</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="508"/>
        <source>Plz select the location to save key file:</source>
        <translation>请选择密钥文件保存的位置：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="509"/>
        <source>Binary Key Files(*.bin *.dump)</source>
        <translation>二进制密码文件(*.bin *.dump)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="636"/>
        <source>    Normally, the Block 0 of a typical Mifare card, which contains the UID, is locked during the manufacture. Users cannot write anything to Block 0 or set a new UID to a normal Mifare card.</source>
        <translation>    普通Mifare卡的块0无法写入，卡号也不能更改</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="637"/>
        <source>    Chinese Magic Cards(aka UID Cards) are some special cards whose Block 0 are writeable. And you can change UID by writing to it.</source>
        <translation>    UID卡（在国外叫中国魔术卡）的块0可写，卡号可变</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="639"/>
        <source>There are two versions of Chinese Magic Cards, the Gen1 and the Gen2.</source>
        <translation>国外把UID卡分为中国魔术卡 Gen1和Gen2</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="640"/>
        <source>    Gen1:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="640"/>
        <source>    also called UID card in China. It responses to some backdoor commands so you can access any blocks without password. The Proxmark3 has a bunch of related commands(csetblk, cgetblk, ...) to deal with this type of card, and my GUI also support these commands.</source>
        <translation>    指通常所说的UID卡，可以通过后门指令直接读写块而无需密码，在PM3和此GUI中有特殊命令处理这类卡片</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="641"/>
        <source>    Gen2:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="641"/>
        <source>    doesn&apos;t response to the backdoor commands, which means that a reader cannot detect whether it is a Chinese Magic Card or not by sending backdoor commands.</source>
        <translation>    这个叫法在国内比较罕见，在国外指CUID/FUID/UFUID这类对后门指令不响应的卡（防火墙卡）</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="643"/>
        <source>There are some types of Chinese Magic Card Gen2.</source>
        <translation>以下是Gen2卡的详细介绍</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="644"/>
        <source>    CUID Card:</source>
        <translation>    CUID卡：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="644"/>
        <source>    the Block 0 is writeable, you can write to this block repeatedly by normal wrbl command.</source>
        <translation>    可通过普通的写块命令来写块0，可重复擦写</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="645"/>
        <source>    (hf mf wrbl 0 A FFFFFFFFFFFF &lt;the data you want to write&gt;)</source>
        <translation>    (hf mf wrbl 0 A FFFFFFFFFFFF &lt;待写入数据&gt;)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="646"/>
        <source>    FUID Card:</source>
        <translation>    FUID卡：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="646"/>
        <source>    you can only write to Block 0 once. After that, it seems like a typical Mifare card(Block 0 cannot be written to).</source>
        <translation>    块0只能写入一次</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="647"/>
        <source>    (some readers might try changing the Block 0, which could detect the CUID Card. In that case, you should use FUID card.)</source>
        <translation>    (更高级的穿防火墙卡，可以过一些能识别出CUID卡的读卡器)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="648"/>
        <source>    UFUID Card:</source>
        <translation>    UFUID卡：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="648"/>
        <source>    It behaves like a CUID card(or UID card? I&apos;m not sure) before you send some special command to lock it. Once it is locked, you cannot change its Block 0(just like a typical Mifare card).</source>
        <translation>    锁卡前和普通UID/CUID卡一样可以反复读写块0，用特殊命令锁卡后就和FUID卡一样了</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="650"/>
        <source>    Seemingly, these Chinese Magic Cards are more easily to be compromised by Nested Attack(it takes little time to get an unknown key).</source>
        <translation>    所有UID卡都似乎更容易被Nested攻击破解</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="696"/>
        <source>Plz select the trace file:</source>
        <translation>请选择trace文件：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="697"/>
        <source>Trace Files(*.trc);;All Files(*.*)</source>
        <translation>Trace文件(*.trc);;所有文件(*.*)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="719"/>
        <source>Plz select the location to save trace file:</source>
        <translation>请选择trace文件保存的位置：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="720"/>
        <source>Trace Files(*.trc)</source>
        <translation>Trace文件(*.trc)</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="805"/>
        <location filename="../ui/mainwindow.cpp" line="960"/>
        <source>Idle</source>
        <translation>空闲</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="812"/>
        <location filename="../ui/mainwindow.cpp" line="821"/>
        <source>Sec</source>
        <translation>扇区</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="813"/>
        <source>Blk</source>
        <translation>块</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="822"/>
        <source>KeyA</source>
        <translation>A密钥</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="823"/>
        <source>KeyB</source>
        <translation>B密钥</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="897"/>
        <source>HW Version:</source>
        <translation>固件版本：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="899"/>
        <source>PM3:</source>
        <translation>连接状态：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="901"/>
        <source>State:</source>
        <translation>运行状态：</translation>
    </message>
    <message>
        <location filename="../ui/mainwindow.cpp" line="956"/>
        <source>Running</source>
        <translation>正在运行</translation>
    </message>
</context>
<context>
    <name>Mifare</name>
    <message>
        <location filename="../module/mifare.cpp" line="592"/>
        <source>Success!</source>
        <translation>成功！</translation>
    </message>
    <message>
        <location filename="../module/mifare.cpp" line="219"/>
        <location filename="../module/mifare.cpp" line="592"/>
        <location filename="../module/mifare.cpp" line="596"/>
        <location filename="../module/mifare.cpp" line="661"/>
        <source>Info</source>
        <translation>信息</translation>
    </message>
    <message>
        <location filename="../module/mifare.cpp" line="219"/>
        <source>Plz provide at least one known key</source>
        <translation>请至少提供一个已知密码</translation>
    </message>
    <message>
        <location filename="../module/mifare.cpp" line="443"/>
        <location filename="../module/mifare.cpp" line="596"/>
        <source>Failed!</source>
        <translation>失败！</translation>
    </message>
    <message>
        <location filename="../module/mifare.cpp" line="661"/>
        <source>Failed to read card.</source>
        <translation>读卡失败。</translation>
    </message>
</context>
</TS>
