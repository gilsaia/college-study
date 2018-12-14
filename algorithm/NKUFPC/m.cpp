#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll listsize=5e5;
ll tofind[2050]={1,154425679,641102369,448516387,578095319,119948046,5832229,929795683,259081142,59433257,974067448,261465122,316220877,663134272,690120224,304661605,251368199,704262886,980250487,386267146,682498929,681184885,134623568,427907847,95936601,140928835,933097914,391177708,167332441,739650465,598816162,292015879,336060741,810640932,248744620,892704918,626497524,118508240,288843364,406755567,491101308,668723114,245341950,560364972,565768255,913230882,246899319,756627904,968999,7998896,586350670,328019447,638587686,497857012,881746146,526658674,19426633,560607302,850500036,916364742,76479948,732041432,268124147,30473806,842267748,878381584,886294336,73995168,485348706,771153434,463847391,72518508,544075857,264638935,898187927,468116664,798967520,359622660,82926604,59761470,723816384,320608814,156530778,278224088,721996174,222176885,299085602,814440466,323604647,359932651,172827403,213590923,398699886,983975503,530389102,619965361,294587621,221896631,813805606,676243000,67347853,557470122,497478507,494243939,196447201,726686688,722054885,435396042,228338256,574429123,407719831,583676448,762479457,342545697,746536789,3669475,811667359,249780014,778773518,306921081,27368307,467386519,438371670,44635470,59469516,498440078,5974669,9221150,766196482,679975009,606322308,147307265,86609485,435993596,889750731,607649469,340941507,886844916,371263376,198057134,625544428,527225600,788878910,743572663,808412394,603835511,996952918,409420559,585237443,307534126,1669644,210601394,361786913,470618701,480748381,550969600,595143852,901560583,837229828,727223125,199888908,180269718,526807168,899715096,579691190,775147177,145404005,401312408,459188207,552930818,534491822,669251006,439729802,504703143,840398449,624903360,899297830,556957390,235861787,850796519,888050723,834568419,656116726,196710441,736550105,857549983,440902696,63145422,85990869,807209645,884343068,132114154,56305184,973762120,973478770,270603374,168891766,217608725,804805577,641317239,927880474,157803266,876297919,189324843,934814019,374934947,676405347,30657162,567277637,686637388,112249297,631678522,44930135,954976637,39417871,977168136,47401357,809639670,108819476,250361638,281863274,410799320,60168088,142840220,692636218,261319829,432775082,200805416,14235602,616435469,770511792,174624465,400295761,580310773,697066277,102309489,421835306,228266417,220108638,334251014,661224977,812005526,261799937,356438399,168203998,835330203,802214249,316146626,544064410,877125482,935080803,576478595,583967898,885117574,211768084,672118586,751231582,192990501,972424306,125666214,623534362,362493992,335160196,924982465,243276029,85322142,554749550,437447268,60050552,733942454,797848181,643938537,395891998,435508211,172428290,422713438,159554990,812391270,887420150,449205554,970055531,222343461,250388809,689850274,487998999,748359168,856259313,29781141,82104855,543656809,232253360,132581614,513365505,443711760,244109365,956163585,1559745,193109503,695345956,36042990,261384175,953585846,849009131,600281990,323214113,762863177,747664143,388430024,444090941,396611787,659224434,991836842,80729842,231753353,570033864,24300293,664989237,653829979,827348878,7704403,195888993,30813167,576798521,947304403,457882808,137550654,731551699,995246811,212938473,593989303,509096183,478919708,827544702,602197504,678320208,496537397,677711203,386677716,289752035,456967785,66404266,208554578,555972231,680796549,195290384,364911332,97136305,294375015,349551356,290196031,785113347,297880214,83489485,644670437,66247239,135500451,52167191,498572695,307390891,499606972,547665832,932668364,143066173,499761057,350016754,113905458,917404120,493905303,296269301,86726457,996122673,809339058,23015220,835803486,602139210,670821828,748566338,631823487,187348575,382748764,109838563,94904185,574053420,973865472,105574531,752194712,304173654,83284607,542432219,536973025,34538816,283727326,325636655,243291133,437843114,312536013,630621321,682680116,26853683,611209607,933245637,894820080,616368450,198631047,238971581,595959409,511371690,683585700,557301633,253427558,911398531,246476028,848952161,272634280,958992544,325284740,925152039,495860053,914456118,841108662,724691727,445713321,636817583,814845293,238087006,170238260,946237212,457433989,910291942,599284582,114985663,17739814,492237273,194710256,450387329,471822076,834860913,831422618,763017204,100582220,368925948,128260642,475812562,917840849,740594930,51595198,45060610,994271859,806047532,476604857,464456846,835245756,172115341,545338291,75307702,344053349,116261993,945918607,562519302,281653965,268838846,635794655,173784895,258300540,243624360,722807834,61570384,691306302,481661251,752609613,938269070,381369130,95182730,885113729,91068149,758827428,115435332,617737077,495022305,641462345,136026497,537165746,506496856,997042337,710729672,185163716,113570024,90871114,366384665,783454081,564758715,75276833,270239666,203381481,277118392,639320111,79874094,366910724,702807165,582981397,112390913,245293699,730341625,338718815,103056890,1840485,677948390,391004385,339464594,145153314,167240465,455408691,108312174,155105232,839079953,605298160,479334442,540479427,271788964,587614008,135498044,861409420,277717575,938160268,591048681,115579849,811637561,629027151,353339603,463734842,889410460,481429323,839849206,296744952,192345193,181445064,736265527,30430299,316439118,844263530,217544623,366151601,788132977,82871673,618898635,693326853,183011467,60732294,380858207,421458551,996097969,207173800,898554793,970529845,335353644,761545908,54062950,385459037,611251733,825396690,419363534,560597174,965429853,105595573,160398980,207103817,151319402,964295934,990918946,850425472,607730875,799102651,450718279,522004028,173539388,39280804,648991369,226831444,970937898,341918865,500780548,177947455,780122909,211496717,39052406,368878414,276894233,276398021,460373282,920539895,651081062,211855474,461415770,853050198,358700839,628370214,643638805,202808666,560006119,186304556,668123525,583546391,686692315,102543936,673464765,397417003,957633609,290432801,199866123,265595990,563432246,785424741,841799766,650453047,385330357,503167666,504962686,352181130,954061253,209208323,128487469,839054128,685707545,922908862,299172297,464643614,717975101,424067031,577786541,61051402,318951960,359014876,773206631,831641758,306832604,59719938,204355779,767173825,573592106,383865684,30977140,760404254,450398100,177740910,363172638,354990705,258379324,74773587,472935553,861711207,93940075,645018357,587220627,82698356,776264326,977544813,793270300,788636352,291733496,55908790,522049725,662927596,579995261,766145844,335416359,851663162,142946099,244577950,472012302,989345508,559947225,118167528,332139472,840577550,499377092,915199651,464599136,585779428,164752359,61316420,309058615,615081450,86117128,241930728,580204973,790715390,563781682,461178318,954840109,435208217,624577416,226031891,895609896,462654883,888287558,660966455,836813268,269404558,926036911,670433353,386027524,204891068,184419613,520697215,724205533,894659709,403351886,726465115,715247054,737530798,716986954,943314229,830567832,534311010,383388563,398145141,68409439,266372070,6734065,251832060,189239124,344955776,68322490,623974296,943653305,697868489,405755338,665567790,811056092,833885272,179518046,844330145,825132993,656058147,343807435,868431947,985084650,575345122,868553027,942820142,148528617,633107927,160684257,961130399,882148737,848419420,591915968,615889822,701445829,545393547,529726489,480474681,302177126,270945720,974886682,488043087,241107368,740529892,798830099,819011249,940567523,876883097,11633075,293918195,325334066,337883503,346091869,51918298,115312728,119960294,473718967,743143063,218129285,926604003,878471898,524012393,180002392,715754,699739374,389016352,917084264,465386262,856859395,301620109,435327356,514251437,808651347,801370191,421623838,382922882,105419548,127456989,59883031,114166180,322487421,900904073,79716267,786066682,715317963,683150470,429277690,64740307,398078032,711401317,316486674,52757021,384843585,849418710,940338439,509520746,937409008,102624539,940524812,787687576,947549662,668564391,833550543,822407919,593524514,192210898,996164327,961867068,987314628,967411361,697611981,394996809,636177449,72168208,274192146,338788555,418537348,463708507,925347821,458367886,952831975,15393104,893732627,987575845,1277567,230566735,358655417,123947564,141866945,844163282,581830879,446827670,987597705,698430079,347046911,651947420,775305697,317604388,125354499,110831147,951540811,952124856,247662371,57339735,343043237,770497428,568392357,330540451,997474832,684274016,209244402,711263223,380480118,152615685,149586983,338740524,392838702,86684635,309134554,210200531,990779998,835720092,263053337,530748609,325362513,228060468,780072518,542860209,551028176,635027430,990826116,982142330,989944961,935582860,155569943,991755346,596737944,25397869,711553356,512486787,268844715,112916884,451373308,944100328,379404150,440154068,462639908,669000996,961812918,346462698,654611901,301178006,382776490,211395011,41815820,183468905,843321396,401648188,675258797,133581040,845583555,836420358,934281721,86418476,741114145,94141511,275105629,390946091,666247477,458436231,325912072,928715741,526131620,530236183,252551589,503759878,432030917,620192986,554917439,762826007,818036959,601095260,754363835,821331296,795190182,739181445,909210595,599067303,278704903,903915339,719566487,571901643,628514947,651386309,424989675,942214416,321685608,250239248,50590510,287162360,832069712,172844240,198768464,329937332,702004730,805897219,99199382,195756808,707469729,310916425,747407118,795864732,302020341,385010048,497196934,515746342,5003231,905975384,726997875,226911103,382617671,907257761,296229203,176691201,183888367,430569820,703397904,662960264,552133875,594030230,732868367,138744932,350095207,303170656,26031303,963071930,863250534,212666452,216665960,757888960,561745549,894162271,352946234,269943732,784139777,389730744,733333339,504457401,503105966,814692089,459878625,100166031,803187381,84186594,16634739,625504439,180898306,815851993,68718097,521750002,985594252,804272708,404206040,625602963,749724532,904212599,97830135,927950630,611751357,336128288,31131935,493898122,662741752,174140647,864326453,214750670,864869025,682983341,167831173,361169784,559214642,316571311,718498895,129884877,91352335,262054502,608823837,30341256,473379392,86738528,385388084,85051770,152267158,883676662,681756977,914781910,46819124,499828799,313132653,300653641,56547945,652279266,442795120,841355804,796616594,186372829,256141983,284655550,152028387,2518954,636578562,665181047,385377759,115557610,553033642,707031841,491415383,267732098,919273670,771891931,996049638,204194403,326686486,524269810,160150665,18364502,141827977,541689171,540818053,444923677,693305776,895259210,593938674,261432589,186576440,525216705,688809790,957610877,565456578,981362547,749296077,246808791,519397500,633032196,551096742,997104085,696628828,473521307,775025061,274750982,370732451,684205655,164246193,919530230,915265013,925117963,457469634,591773508,923043932,579491909,912368644,657283032,777901604,580108890,464118005,619229549,637939935,875658633,956856710,390856783,490676632,404533909,453019482,191649870,462528877,13751809,502297454,629218582,798895521,623841561,100498586,77511478,699767918,416820652,849974789,741447563,811575797,747107591,438952959,248233087,606870929,32074225,907720182,999821136,179111720,778287926,48053248,966053837,508038818,433786890,811944661,631265590,752550134,739608890,401382061,623047959,848924691,730897743,764368449,605025034,34629406,894517500,529840945,112657644,435904287,997813035,26011548,56222592,208184231,198012676,446477394,672903454,206330671,181069006,366033520,504590032,131772368,213456517,185646898,713536809,648711554,187129040,472759660,446982306,523696723,306339620,271198437,284132069,25058942,971058102,859369491,255041381,817928963,136849970,330711333,742765041,724464507,730186918,437605233,864978329,701453022,133269512,626663115,11085731,281230685,141658162,510650790,527887355,596949867,731147272,295726547,613729514,303076380,514155754,465070856,415213535,272814771,684096122,538771609,579671055,48824684,972590066,951279549,217176278,939889684,957342287,564188856,469432979,48527183,119648328,201307702,264639326,484458461,337340034,861754542,974596348,326159309,774336224,181594759,287297719,668422905,860780776,286273596,467363131,965656187,570457971,44135644,938561592,359960756,255726848,936229527,586418403,407934361,577750062,267193060,110628267,456152084,748372491,459116722,496690748,124804049,778806615,262322489,471005141,920251227,881907746,816929577,71346633,483924582,885773623,151834896,697422579,167087470,348461966,490222511,271101205,903466878,695845167,361583925,139849160,368114731,611223434,339383292,240693388,388728584,787495569,218107212,647286378,249153339,301439625,909458706,825527586,322908524,713473839,202649964,316700583,92255682,619301661,573074791,265672103,15570863,330425149,94331513,80303342,744158074,714604162,196345098,956948468,334326205,656410044,9416035,98875930,98349682,249359071,882121662,609122097,769795511,27204169,231988936,341541162,888146074,563593105,137603545,597887794,582627184,173167319,407518072,525248491,919419361,34084880,909433461,459822212,986708498,578423178,310317874,688545487,373745190,426767514,263645931,33023513,256853930,216838327,876379959,681776798,702823274,152276951,147050765,552142680,308186532,892943080,175504139,531982651,180350107,853751105,797736554,911931389,606241871,734505544,384547635,205897697,273712630,295898944,586444655,298511537,682189174,391491433,666493603,769644373,946867127,779729071,819114541,430345388,502371023,565093850,261970285,73676677,825871994,439985219,126925175,537175030,701506133,922419422,314738056,331629774,341779962,993829303,561011609,310187903,815463367,419922946,46765164,153796383,49187570,978824517,188054995,229507993,957939114,976365496,64814326,34962064,933376898,639423687,329837066,938220928,338121343,723473543,765215899,374248877,869630152,825793239,978119194,712565751,632627667,996588391,975266085,10259433,435887178,310651169,282092463,235000767,129621197,131119231,758245605,122477672,827722926,104141028,201339230,632232583,918513230,9760876,322096036,661083628,547838438,278005187,985546115,462757650,852304035,747700707,593090119,31738433,689189630,302579083,555842733,407991608,567033437,883930382,469928208,933753541,212842957,952917862,117842065,636059822,404149413,5021656,155133422,396892116,663307737,252202515,208761293,556478432,206282795,438269075,717946122,308402114,488906585,58731649,414236650,138477462,280700600,829290435,962670136,691030367,534279149,534216193,214569244,306753329,375297772,506050984,811053196,768114732,922377372,685756954,289594327,77516399,219932130,423659297,211487466,88929658,701050258,207594892,398782410,311095371,863002719,558395120,27236531,653991930,217598709,6140104,375472836,227970396,810551911,759994826,178598958,212759058,247844667,738789531,676526196,935116236,812283640,270258531,863066876,523449284,857241854,244920548,113917835,285558056,624148346,217519213,726089763,288577505,564827277,182270197,826300950,154134669,478982047,992035084,439411911,781040881,454039189,173642567,633292726,181058575,48562889,316466042,802100365,528654390,671734977,588427118,945204804,617419803,508831870,923976569,398781902,345695843,897162044,488776232,644050694,522005226,892168027,663939743,828883117,636309857,277714559,22220478,713448377,862322982,624500515,670822030,590098114,282104097,808691930,671075979,514359662,161646605,895205045,18763728,715264908,171766217,628829100,727088567,484492064,847440256,919717789,118695128,513196123,1927054,748510389,604018013,403652653,900440408,574455974,135656153,77123823,195346599,172096141,796894379,819801784,102159868,581418893,26773666,15655126,961808256,15391652,340290036,875641535,25732221,203191898,762975242,264582598,186922308,880691101,828454217,907800444,342392035,986598821,200084575,340030191,556841547,264688936,275811253,369832433,444094748,785804644,277341268,842065079,898092098,423951674,207638534,663560047,230631176,696623384,807827182,496709826,879400608,161960209,865140964,331910086,603116309,541120825,574610474,951524114,962158915,841656666,662109025,162683802,60582516,629786193,883014120,190395535,472550413,269571439,468747428,832671304,125435851,76770272,470689842,341080135,207220566,421943723,324979737,494210290,604177687,751040886,95589267,317076664,717683969,672850561,988189352,72482816,161579561,493689107,388537544,135625240,555187833,100228913,728822117,684748812,576796201,639655136,266200149,906233141,85157309,929893103,133047646,277813439,9837620,814362881,380021947,562608724,213027699,406024012,315587760,885537778,925665844,10065330,107125810,60625018,376366561,983737173,253250904,60517502,466459786,551060742,139998669,804930491,592347496,823845496,765555389,727416538,590444719,946421040,717927112,678171399,86811998,842203531,371706626,175638827,408502422,894247956,831246288,538609927,782723657,885362182,831257253,946464959,453770195,116667533,982647665,749816133,712106516,241427979,710965692,871117927,378998132,281804989,603830959,163928347,644386154,563796647,274795785,640266394,107234102,774625892,791185412,59342705,97826191,256473217,590213099,674115061,703665287,918860977,8947163,322633051,192270447,753513874,294830834,393556719,25181126,304644842,234845827,767372800,553063981,161362528,749473336,754787150,58596576,627655552,159512462,677395736,846532820,799289297,354655649,846650652,978805070,816701166,315419580,687265514,833548006,787113234,97846412,358757251,226478218,701220427,567481117,607715125,90197399,245795606,962901304,600624983,242901954,10475577,650859047,728620948,435811032,759404319,573183959,36292292,183555163,491466901,447239215,22556579,873791394,114495791,197736875,647630109,485056460,586445753,190508668,482254337,322924180,718623833,116698549,763514207,810987160,66547751,300695571,953634340,324833924,351472920,384343273,308474522,20450004,494166907,85288039,634359666,397059212,172114298,198532616,865440961,3739182,364380585,990631624,921648059,903288230,965683742,374214450,260466949,112429098,117483873,281744795,962540888,642772349,237120480,504371008,620531822,563045796,193781724,695511574,213092254,782794242,107141741,662565976,602742426,857268414,793307102,919116765,756154604,443183564,236455213,626871594,362928234,938420738,14162538,801639277,753042874,723950758,778983779,672909594,25977209,323582350,49389215,254189314,698308420,181353334,859637374,801413581,49031023,709178470,713258160,410465453,737331920,131731042,923333660,601117743,804861409,327520749,83868974,260831555,682873215,937240859,217298111,659873007,883278906,366761197,176966527,110744650,954913,246965865,105359006,338471174,390019735,549660657,10430738,58007504,706334445,864696066,315103615,465054749,567473423,85292764,708233401,426786760,48160594,142441517,946149627,394265229,346966053,71050762,281329488,246955022,462880311,253486451,31503476,411673788,185438078,521591989,965785236,16651371,992656683,545638190,916291845,65591903,881482632,957757479,899946391,84428155,321900901,674721611,512634493,970053019,303338827,860842034,121000338,87654126,967284733,580938783,492741665,671517513,152233223,335102896,165393390,160150497,680128316,685723887,917041303,782192657,532702135,56081734,741626808,642939667,496442755,867195255,536841269,412622873,131384366,994065976,377329025,974508445,301196854,574480664,859917803,20211256,676511002,437157360,373451745,83118246,847645126,268761837,823495900,459628134,576368335,494290402,73146164,98016105,954958912,486828649,847549272,201882845,241289571,420567331,646654592,788599446,216046746,682599498,205951465,383521365,3258987,433576760,780882948,510148825,822439091,128900492,598245292,606924610,869544707,933768689,698611116};
ll pos=1;
ll findmod(ll n)
{
    ll ans=tofind[n/listsize];
    for(ll i=(n/listsize)*listsize+1;i<=n;++i)
    {
        ans=ans*i%MOD;
    }
    return ans;
}
ll extgcd(ll a,ll b,ll &x,ll &y)
{
    ll d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
ll mod_inverse(ll a,ll m)
{
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
ll mod_pow(ll x,ll n,ll mod)
{
    ll res=1;
    while(n>0)
    {
        if(n&1)
        {
            res=res*x%mod;
        }
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
ll save[15020],C[15020];
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;++i)
    {
        ll n,m;
        scanf("%lld%lld",&n,&m);
        for(int j=0;j<m;++j)
        {
            int tmpa,tmpb;
            scanf("%d%d",&tmpa,&tmpb);
        }
        ll firsttmp=findmod(n*2-m);
        save[0]=firsttmp;
        for(ll i=1;i<=m;++i)
        {
            firsttmp=save[i]=firsttmp*(2*n-m+i)%MOD;
        }
        C[0]=1;
        for(ll i=1;i<=m;++i)
        {
            ll tmp=(C[i-1]*(m-i+1))%MOD;
            tmp=tmp*mod_inverse(i,MOD)%MOD;
            C[i]=tmp;
        }
        ll ans=0,twopow=1;
        for(int i=0;i<=m;++i)
        {
            ll tmp=C[i]*save[m-i]%MOD;
            tmp=tmp*twopow%MOD;
            ans=(ans+tmp)%MOD;
            twopow=twopow*(-2)%MOD;
        }
        while(ans<0)
        {
            ans+=MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}