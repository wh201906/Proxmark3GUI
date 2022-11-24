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
        <location filename="../src/ui/mf_sim_simdialog.ui" line="38"/>
        <source>u</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="67"/>
        <source>UID 4 or 7 bytes. If not specified, the UID 4B from emulator memory will be used</source>
        <translation>4或7字节的UID，如果不指定，则使用模拟器内存中的4字节UID</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="105"/>
        <source>--atqa</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="134"/>
        <source>Provide explicit ATQA (2 bytes)</source>
        <translation>指定ATQA（2个字节）</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="172"/>
        <source>--sak</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="201"/>
        <source>Provide explicit SAK (1 byte)</source>
        <translation>指定SAK（1个字节）</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="239"/>
        <source>n</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="268"/>
        <source>Automatically exit simulation after &lt;numreads&gt; blocks have been read by reader. 0 = infinite</source>
        <translation>在读卡器读取&lt;n&gt;个块后自动退出模拟，n为0或不指定时永远不退出</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="306"/>
        <source>i</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="319"/>
        <source>Interactive, means that console will not be returned until simulation finishes or is aborted</source>
        <translation>交互模式，勾选后PM3客户端将在模拟完成或者模拟中断后才可继续使用</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="357"/>
        <source>x</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="370"/>
        <source>Crack, performs the &apos;reader attack&apos;, nr/ar attack against a legitimate reader, fishes out the key(s)</source>
        <translation>破解，对读卡器进行攻击，通过nr/ar攻击来钓出密码(无卡嗅探)</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="408"/>
        <source>e</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="421"/>
        <source>set keys found from &apos;reader attack&apos; to emulator memory (implies x(--crack) and i)</source>
        <translation>在获得密码后自动将密码写入模拟器内存（自动勾选x(--crack)和i）</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="577"/>
        <source>-v</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="590"/>
        <source>verbose output</source>
        <translation>更多输出内容</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="459"/>
        <source>f</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="488"/>
        <source>get UIDs to use for &apos;reader attack&apos; from file &apos;f &lt;filename.txt&gt;&apos; (implies x and i)</source>
        <translation>从&lt;filename.txt&gt;当中获取用于破解读卡器的UID（批量模拟）（自动勾选x和i）</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_sim_simdialog.ui" line="526"/>
        <source>r</source>
        <translation></translation>
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
    <message>
        <location filename="../src/ui/mf_uid_parameterdialog.ui" line="22"/>
        <source>UID:</source>
        <translation>卡号：</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_uid_parameterdialog.ui" line="32"/>
        <source>ATQA:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_uid_parameterdialog.ui" line="42"/>
        <source>SAK:</source>
        <translation></translation>
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
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="28"/>
        <source>4</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="38"/>
        <source>16</source>
        <translation></translation>
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
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="134"/>
        <source>Cx0</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="155"/>
        <source>Cx1</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="176"/>
        <source>Cx2</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="197"/>
        <source>Cx3</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="235"/>
        <source>Data Block Permission:</source>
        <translation>数据块访问权限：</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="252"/>
        <source>Block0</source>
        <translation>块0</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="257"/>
        <source>Block1</source>
        <translation>块1</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="262"/>
        <source>Block2</source>
        <translation>块2</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="267"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="307"/>
        <source>Read</source>
        <translation>读</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="272"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="312"/>
        <source>Write</source>
        <translation>写</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="277"/>
        <source>Increase</source>
        <translation>增加</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="282"/>
        <source>Decrease/Transfer/Restore</source>
        <translation>减少/从缓冲区写入/读入至缓冲区</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="290"/>
        <source>Trailer Block Permission:</source>
        <translation>Trailer访问权限：</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="317"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="113"/>
        <source>KeyA</source>
        <translation>密钥A</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="322"/>
        <source>Access Bits</source>
        <translation>控制位</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="327"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="117"/>
        <source>KeyB</source>
        <translation>密钥B</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="337"/>
        <source>Reference:
MF1S70YYX_V1 Product data sheet
Rev. 3.2 — 23 November 2017</source>
        <translation>参考资料：
MF1S70YYX_V1 Product data sheet
Rev. 3.2 — 23 November 2017</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.ui" line="358"/>
        <source>Note:the Access Bits usually contains 4 bytes(8 hex symbols), but only the first 3 bytes matters. You can set the 4th byte randomly.</source>
        <translation>注意：Access Bits一般包含4个字节（8个16进制字符），但只有前3个字节决定访问情况，最后一个字节可任意设置。</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="43"/>
        <source>Invalid!
It could make the whole sector blocked irreversibly!</source>
        <translation>无效！
可能导致整个扇区被不可逆转地锁定！</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="52"/>
        <source>Valid</source>
        <translation>有效</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="88"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="89"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="90"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="94"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="95"/>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="96"/>
        <source>Block</source>
        <translation>块</translation>
    </message>
    <message>
        <location filename="../src/ui/mf_trailerdecoderdialog.cpp" line="121"/>
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
        <location filename="../src/ui/mainwindow.ui" line="111"/>
        <source>Connect</source>
        <translation>连接</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="124"/>
        <source>Disconnect</source>
        <translation>断开</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="143"/>
        <source>Mifare</source>
        <translation>Mifare(IC)卡</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="246"/>
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
        <location filename="../src/ui/mainwindow.ui" line="213"/>
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
        <location filename="../src/ui/mainwindow.cpp" line="886"/>
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
        <location filename="../src/ui/mainwindow.ui" line="72"/>
        <source>Port:</source>
        <translation>端口：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="98"/>
        <source>Refresh Ports</source>
        <translation>刷新端口</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="239"/>
        <source>Select All</source>
        <translation>全选</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="275"/>
        <source>KeyBlocks-&gt;Key</source>
        <translation>密码区-&gt;密码</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="288"/>
        <source>KeyBlocks&lt;-Key</source>
        <translation>密码区&lt;-密码</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="301"/>
        <source>Fill Keys</source>
        <translation>填充密码</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="314"/>
        <source>Trailer Decoder</source>
        <translation>Trailer解码</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="327"/>
        <source>Set Fonts</source>
        <translation>设置字体</translation>
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
        <location filename="../src/ui/mainwindow.ui" line="1302"/>
        <source>125k</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="1318"/>
        <source>134k</source>
        <translation></translation>
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
        <location filename="../src/ui/mainwindow.cpp" line="47"/>
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
        <location filename="../src/ui/mainwindow.cpp" line="318"/>
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
        <location filename="../src/ui/mainwindow.ui" line="2650"/>
        <source>Client</source>
        <translation>客户端</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2656"/>
        <source>GUI working directory:</source>
        <translation>GUI工作路径：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2711"/>
        <source>../data</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2742"/>
        <source>&lt;port&gt; -f</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2766"/>
        <source>Config file(Reconnect to apply):</source>
        <translation>配置文件(重连后生效)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2917"/>
        <source>Language: </source>
        <translation>语言： </translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2924"/>
        <source>Choose Language</source>
        <translation>选择语言</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2931"/>
        <source>(Restart this app to use new language)</source>
        <translation>（重启此程序以使用新语言）</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2848"/>
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
        <location filename="../src/ui/mainwindow.ui" line="2673"/>
        <source>Preload script path(Reconnect to apply):</source>
        <translation>预加载脚本路径(重连后生效)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2687"/>
        <source>If the client requires some enviroment variables, you can make a script file(*.bat on Windows or *.sh on Linux) to configure them, then put the path of the script there.</source>
        <translation>如果客户端需要配置环境变量才能正常运行，可以将配置环境变量所需的脚本文件(Windows系统内为*.bat，linux系统内为*.sh)路径填入此处。</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2704"/>
        <source>Client working directory(Reconnect to apply):</source>
        <translation>客户端工作路径(重连后生效)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2718"/>
        <source>On Windows, the client working directory should not be identical to the path of GUI, otherwise the client will use the wrong .dll file.</source>
        <translation>在Windows系统中，客户端工作路径与GUI程序所在路径不能相同，否则客户端会使用错误的.dll文件。</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2735"/>
        <source>Start arguments(Reconnect to apply):</source>
        <translation>启动参数(重连后生效)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2749"/>
        <source>-f is necessary because the GUI need to handle the output in time. In some cases, the arguments should be set to &quot;-p /dev/&lt;port&gt; -f&quot; or &quot;-p &lt;port&gt; -f&quot;.</source>
        <translation>-f选项用于使客户端实时返回命令回显，必须添加。部分情况下启动参数需设置为&quot;-p /dev/&lt;port&gt; -f&quot;或&quot;-p &lt;port&gt; -f&quot;。</translation>
    </message>
    <message>
        <source>Config file path(Reconnect to apply):</source>
        <translation type="vanished">配置文件路径(重连后生效)：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2797"/>
        <source>config.json</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2804"/>
        <source>Different clients require different config files. You can change the content of config file if the command format changes.</source>
        <translation>不同客户端需要使用不同的配置文件。若命令格式发生改变，你可以尝试手动修改配置文件以适配。</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2894"/>
        <source>Keep the client active even the PM3 hardware is disconnected.(Experimental)</source>
        <translation>在PM3断开后保持客户端运行（实验性功能）</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="2909"/>
        <source>GUI</source>
        <translation>图形化界面</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="90"/>
        <location filename="../src/ui/mainwindow.cpp" line="167"/>
        <location filename="../src/ui/mainwindow.cpp" line="235"/>
        <location filename="../src/ui/mainwindow.cpp" line="240"/>
        <location filename="../src/ui/mainwindow.cpp" line="421"/>
        <location filename="../src/ui/mainwindow.cpp" line="647"/>
        <location filename="../src/ui/mainwindow.cpp" line="667"/>
        <location filename="../src/ui/mainwindow.cpp" line="680"/>
        <location filename="../src/ui/mainwindow.cpp" line="699"/>
        <location filename="../src/ui/mainwindow.cpp" line="712"/>
        <location filename="../src/ui/mainwindow.cpp" line="739"/>
        <location filename="../src/ui/mainwindow.cpp" line="752"/>
        <location filename="../src/ui/mainwindow.cpp" line="944"/>
        <location filename="../src/ui/mainwindow.cpp" line="969"/>
        <source>Info</source>
        <translation>信息</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="167"/>
        <source>Plz choose a port first</source>
        <translation>请先选择端口</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="251"/>
        <source>Connected</source>
        <translation>已连接</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="257"/>
        <location filename="../src/ui/mainwindow.cpp" line="1054"/>
        <source>Not Connected</source>
        <translation>未连接</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="699"/>
        <location filename="../src/ui/mainwindow.cpp" line="712"/>
        <location filename="../src/ui/mainwindow.cpp" line="944"/>
        <source>Failed to open</source>
        <translation>无法打开</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="421"/>
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
        <location filename="../src/ui/mainwindow.cpp" line="90"/>
        <source>Failed to load config file</source>
        <translation>无法打开配置文件</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="235"/>
        <source>Failed to start the client</source>
        <translation>无法启动客户端</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="240"/>
        <source>Failed to connect to the hardware</source>
        <translation>无法连接到PM3硬件</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="421"/>
        <source>Some of the data and key will be cleared.</source>
        <translation>部分数据和密码将被清除</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="534"/>
        <source>Plz select the font of data widget and key widget</source>
        <translation>请选择数据窗口和密钥窗口的字体</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="647"/>
        <source>Data must consists of 32 Hex symbols(Whitespace is allowed)</source>
        <translation>数据必须由32个十六进制字符组成（中间可含有空格）</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="667"/>
        <location filename="../src/ui/mainwindow.cpp" line="680"/>
        <source>Key must consists of 12 Hex symbols(Whitespace is allowed)</source>
        <translation>密钥必须由12个十六进制字符组成（中间可含有空格）</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="692"/>
        <source>Plz select the data file:</source>
        <translation>请选择数据文件：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="693"/>
        <location filename="../src/ui/mainwindow.cpp" line="733"/>
        <location filename="../src/ui/mainwindow.cpp" line="737"/>
        <source>Binary Data Files(*.bin *.dump)</source>
        <translation>二进制数据文件(*.bin *.dump)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="693"/>
        <location filename="../src/ui/mainwindow.cpp" line="706"/>
        <location filename="../src/ui/mainwindow.cpp" line="931"/>
        <source>All Files(*.*)</source>
        <translation>所有文件(*.*)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="705"/>
        <source>Plz select the key file:</source>
        <translation>请选择密钥文件：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="732"/>
        <source>Plz select the location to save data file:</source>
        <translation>请选择数据文件保存的位置：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="739"/>
        <location filename="../src/ui/mainwindow.cpp" line="752"/>
        <location filename="../src/ui/mainwindow.cpp" line="969"/>
        <source>Failed to save to</source>
        <translation>无法保存至</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="745"/>
        <source>Plz select the location to save key file:</source>
        <translation>请选择密钥文件保存的位置：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="706"/>
        <location filename="../src/ui/mainwindow.cpp" line="746"/>
        <location filename="../src/ui/mainwindow.cpp" line="750"/>
        <source>Binary Key Files(*.bin *.dump)</source>
        <translation>二进制密码文件(*.bin *.dump)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="693"/>
        <location filename="../src/ui/mainwindow.cpp" line="733"/>
        <source>Text Data Files(*.txt *.eml)</source>
        <translation>文本数据文件(*.txt *.eml)</translation>
    </message>
    <message>
        <source>Text Key Files(*.txt *.eml)</source>
        <translation type="vanished">文本密码文件(*.txt *.eml)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="871"/>
        <source>    Normally, the Block 0 of a typical Mifare card, which contains the UID, is locked during the manufacture. Users cannot write anything to Block 0 or set a new UID to a normal Mifare card.</source>
        <translation>    普通Mifare卡的块0无法写入，卡号也不能更改</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="872"/>
        <source>    Chinese Magic Cards(aka UID Cards) are some special cards whose Block 0 are writeable. And you can change UID by writing to it.</source>
        <translation>    UID卡（在国外叫Chinese Magic Card）的块0可写，卡号可变。</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="874"/>
        <source>There are two versions of Chinese Magic Cards, the Gen1 and the Gen2.</source>
        <translation>国外把UID卡分为Chinese Magic Card Gen1和Gen2</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="875"/>
        <source>    Gen1:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="875"/>
        <source>    also called UID card in China. It responses to some backdoor commands so you can access any blocks without password. The Proxmark3 has a bunch of related commands(csetblk, cgetblk, ...) to deal with this type of card, and my GUI also support these commands.</source>
        <translation>    指通常所说的UID卡，可以通过后门指令直接读写块而无需密码，在PM3和此GUI中有特殊命令处理这类卡片</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="876"/>
        <source>    Gen2:</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="876"/>
        <source>    doesn&apos;t response to the backdoor commands, which means that a reader cannot detect whether it is a Chinese Magic Card or not by sending backdoor commands.</source>
        <translation>    这个叫法在国内比较罕见，在国外指CUID/FUID/UFUID这类对后门指令不响应的卡（防火墙卡）</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="878"/>
        <source>There are some types of Chinese Magic Card Gen2.</source>
        <translation>以下是Gen2卡的详细介绍</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="879"/>
        <source>    CUID Card:</source>
        <translation>    CUID卡：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="879"/>
        <source>    the Block 0 is writeable, you can write to this block repeatedly by normal wrbl command.</source>
        <translation>    可通过普通的写块命令来写块0，可重复擦写</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="880"/>
        <source>    (hf mf wrbl 0 A FFFFFFFFFFFF &lt;the data you want to write&gt;)</source>
        <translation>    (hf mf wrbl 0 A FFFFFFFFFFFF &lt;待写入数据&gt;)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="881"/>
        <source>    FUID Card:</source>
        <translation>    FUID卡：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="881"/>
        <source>    you can only write to Block 0 once. After that, it seems like a typical Mifare card(Block 0 cannot be written to).</source>
        <translation>    块0只能写入一次</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="882"/>
        <source>    (some readers might try changing the Block 0, which could detect the CUID Card. In that case, you should use FUID card.)</source>
        <translation>    (更高级的穿防火墙卡，可以过一些能识别出CUID卡的读卡器)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="883"/>
        <source>    UFUID Card:</source>
        <translation>    UFUID卡：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="883"/>
        <source>    It behaves like a CUID card(or UID card? I&apos;m not sure) before you send some special command to lock it. Once it is locked, you cannot change its Block 0(just like a typical Mifare card).</source>
        <translation>    锁卡前和普通UID/CUID卡一样可以反复读写块0，用特殊命令锁卡后就和FUID卡一样了</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="885"/>
        <source>    Seemingly, these Chinese Magic Cards are more easily to be compromised by Nested Attack(it takes little time to get an unknown key).</source>
        <translation>    所有UID卡都似乎更容易被Nested攻击破解</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="930"/>
        <source>Plz select the trace file:</source>
        <translation>请选择trace文件：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="954"/>
        <source>Plz select the location to save trace file:</source>
        <translation>请选择trace文件保存的位置：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1128"/>
        <source>External file</source>
        <translation>外部文件</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="931"/>
        <location filename="../src/ui/mainwindow.cpp" line="955"/>
        <source>Trace Files(*.trc)</source>
        <translation>Trace文件(*.trc)</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1055"/>
        <location filename="../src/ui/mainwindow.cpp" line="1247"/>
        <source>Idle</source>
        <translation>空闲</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1057"/>
        <source>Stop</source>
        <translation>停止</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="203"/>
        <location filename="../src/ui/mainwindow.ui" line="380"/>
        <source>Sec</source>
        <translation>扇区</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.ui" line="208"/>
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
        <location filename="../src/ui/mainwindow.cpp" line="1184"/>
        <source>HW Version:</source>
        <translation>固件版本：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1186"/>
        <source>PM3:</source>
        <translation>连接状态：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1188"/>
        <source>State:</source>
        <translation>运行状态：</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1243"/>
        <source>Running</source>
        <translation>正在运行</translation>
    </message>
    <message>
        <location filename="../src/ui/mainwindow.cpp" line="1370"/>
        <source>Actural Freq: </source>
        <translation>实际频率： </translation>
    </message>
</context>
<context>
    <name>Mifare</name>
    <message>
        <location filename="../src/module/mifare.cpp" line="642"/>
        <source>Success!</source>
        <translation>成功！</translation>
    </message>
    <message>
        <location filename="../src/module/mifare.cpp" line="208"/>
        <location filename="../src/module/mifare.cpp" line="642"/>
        <location filename="../src/module/mifare.cpp" line="646"/>
        <location filename="../src/module/mifare.cpp" line="670"/>
        <location filename="../src/module/mifare.cpp" line="713"/>
        <location filename="../src/module/mifare.cpp" line="726"/>
        <location filename="../src/module/mifare.cpp" line="783"/>
        <source>Info</source>
        <translation>信息</translation>
    </message>
    <message>
        <location filename="../src/module/mifare.cpp" line="208"/>
        <source>Plz provide at least one known key</source>
        <translation>请至少提供一个已知密码</translation>
    </message>
    <message>
        <location filename="../src/module/mifare.cpp" line="467"/>
        <location filename="../src/module/mifare.cpp" line="646"/>
        <source>Failed!</source>
        <translation>失败！</translation>
    </message>
    <message>
        <location filename="../src/module/mifare.cpp" line="671"/>
        <source>The Access Bits is invalid!
It could make the whole sector blocked irreversibly!
Continue to write?</source>
        <translation>控制位无效！
使用该控制位可能导致目标扇区损坏且无法恢复！
确定要写入吗？</translation>
    </message>
    <message>
        <location filename="../src/module/mifare.cpp" line="713"/>
        <source>Successful!</source>
        <translation>成功！</translation>
    </message>
    <message>
        <location filename="../src/module/mifare.cpp" line="726"/>
        <source>Failed to write to these blocks:</source>
        <translation>写入以下块失败：</translation>
    </message>
    <message>
        <location filename="../src/module/mifare.cpp" line="730"/>
        <source>Select them?</source>
        <translation>选中这些块？</translation>
    </message>
    <message>
        <location filename="../src/module/mifare.cpp" line="783"/>
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
        <location filename="../src/ui/t55xxtab.ui" line="32"/>
        <source>T5555</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/t55xxtab.ui" line="39"/>
        <source>T55x7</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/ui/t55xxtab.ui" line="64"/>
        <source>EM410x</source>
        <translation></translation>
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
