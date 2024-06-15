#ifndef __LENET_5_D7_PARAMS_H__
#define __LENET_5_D7_PARAMS_H__

#include <general_settings.h>
#include <cnn_features.h>

feature_t biases_d7[D7_OUTPUT_SIZE] = {
   -0.056460865
    , -0.03162331
    , -0.04091932
    , 0.032413736
    , -0.008790147
    , 0.00062382355
    , -0.022162877
    , -0.024575388
    , 0.09399677
    , 0.0019831003 
};

feature_t weights_d7[D7_INPUT_SIZE*D7_OUTPUT_SIZE] = {
     -0.061001673,0.17363232,-0.14200397,0.038344435,0.03028013,-0.0724485,-0.17594784,-0.056823175,0.15062875,0.09096237
    , 0.080346994,0.004253098,0.0005235666,-0.100412324,-0.06508583,-0.20212911,-0.39008448,0.19687115,-0.17848828,0.22679584
    , 0.122374505,-0.22958276,-0.034518823,0.24845082,-0.3844298,0.024652196,0.26224402,0.027656808,-0.11532621,-0.18615961
    , -0.0883464,-0.1524287,0.16738361,-0.01219857,-0.071444616,-0.0537211,-0.24293604,-0.1705762,-0.10841358,-0.17149541
    , -0.0752067,-0.19651543,-0.23433092,0.026325002,0.31393927,0.08008856,0.26001334,-0.2581424,0.30767223,-0.16367485
    , 0.15978394,-0.22147045,0.14697553,0.22682153,-0.062939584,-0.11519816,0.2311726,0.11969766,0.026141947,-0.24548015
    , 0.0039564725,-0.2157555,-0.07350114,0.108401775,0.018783337,-0.09935976,-0.20453675,-0.14518818,-0.017016908,-0.0813728
    , 0.064714044,0.089508034,-0.16683367,0.10368927,-0.10328215,0.21686158,0.1611181,-0.09688001,-0.21289423,0.22385
    , -0.099576086,0.20808499,0.16926038,-0.14950933,0.025504293,-0.433278,-0.007850251,0.16057469,-0.3106597,-0.07635433
    , -0.16880971,0.09575583,0.13331865,-0.2364666,0.24839476,0.2228309,0.25315556,0.056005854,0.11421408,-0.104233205
    , 0.0120927915,-0.066064335,-0.2598646,0.045129754,0.055078,-0.26425746,-0.22687364,0.13336304,-0.07243246,-0.066563964
    , -0.122517966,0.2918912,0.11995891,0.3168867,-0.30444834,0.076002784,-0.22118106,0.22912799,-0.30146155,-0.2331356
    , 0.18947649,0.19983095,-0.0015664531,0.20512396,-0.035225768,-0.03031943,-0.08616765,-0.22113757,-0.024208318,-0.22047049
    , -0.3229649,-0.37768614,0.07683499,-0.18644223,-0.09083008,-0.23410818,-0.23597501,0.13703315,0.15040413,0.16531444
    , -0.06772961,0.1443777,0.21285477,-0.05879026,-0.37532532,-0.25246865,-0.26952064,0.10085286,0.057483006,-0.1767468
    , 0.26279947,0.10223037,-0.24259582,-0.24017707,-0.335023,0.2834876,0.16593263,0.14065461,0.017363442,-0.056011695
    , 0.023821669,-0.11055814,0.36781096,-0.019945173,-0.24078028,0.1781231,0.056376584,0.09174687,-0.29107508,-0.116977416
    , -0.11918373,-0.20411167,0.15924224,0.08795319,-0.092967056,-0.123011656,0.07373559,-0.15620078,0.16801512,0.09771675
    , -0.27862707,-0.14339752,-0.26687354,-0.031543735,-0.031389654,-0.33127445,-0.24595192,-0.33022016,-0.31463397,0.06996862
    , -0.13966429,-0.013110242,0.113095075,-0.12757896,-0.14881642,-0.39735666,-0.45854878,0.22119963,0.2496806,-0.21848969
    , 0.10511355,0.121814735,0.14630924,-0.25051036,0.12383899,-0.12446763,-0.021931121,0.26161277,-0.0236011,-0.19114073
    , 0.23004645,0.02062303,-0.05991128,-0.33700877,0.23257956,-0.38514456,-0.17372015,-0.15218164,0.1575298,-0.080227315
    , 0.09127905,-0.39584926,0.057659198,-0.19378552,-0.1769344,-0.00980231,-0.036895655,-0.40639117,-0.2844622,0.019759513
    , -0.2218036,0.05530316,0.014519977,-0.30531052,-0.053725153,0.11007567,0.04698019,-0.094712734,-0.15495458,-0.23029931
    , -0.25744227,0.22709127,-0.014042188,0.13562052,-0.27665806,-0.063553326,0.20220388,-0.22596663,0.09476149,-0.299563
    , 0.08158515,-0.16139525,0.077424206,0.22570671,0.17082189,-0.16938931,-0.44385067,-0.00037878883,-0.051728632,-0.07631567
    , -0.21869932,0.03236598,-0.24269931,-0.32140446,0.03908138,-0.043643538,-0.24629332,0.13069095,-0.30841854,0.0997764
    , -0.19065033,-0.27899754,0.13547929,0.10488935,0.209322,0.21483056,-0.23538552,0.1387115,-0.2617172,0.02825447
    , -0.29147822,0.117189,0.16951966,-0.11405743,-0.27950028,0.08659603,-0.09616701,-0.27043715,0.003683969,-0.0956457
    , -0.29616785,-0.16390698,0.09072199,0.25873834,0.05740284,-0.17062446,0.0068390486,0.17148443,0.16765983,0.17053679
    , 0.3110255,-0.051712673,0.0136954,-0.2808227,0.17550239,-0.35650462,0.16212568,-0.508096,0.047493324,0.06731052
    , 0.18199241,-0.08243594,-0.1459135,-0.33047163,0.25991246,-0.13818191,0.2497853,-0.28902394,-0.34272808,0.068532474
    , 0.22127308,-0.07275199,-0.119711354,0.27302808,-0.5831185,-0.059740625,0.067934535,-0.10237707,0.27744266,-0.17620751
    , -0.16996069,0.043384474,-0.32159916,-0.07920736,-0.008210912,0.31306067,0.3182558,-0.025567345,-0.16215296,-0.29577348
    , 0.28607884,-0.08434168,-0.2395421,-0.07559806,0.047998197,0.30709383,-0.14758639,0.032736305,-0.29102576,0.34321514
    , 0.2504572,0.27626273,0.15240815,-0.15459238,0.04158831,0.069150746,-0.18206893,0.17137334,-0.2776634,-0.09479349
    , -0.50008154,0.22989425,-0.3427179,-0.23233114,-0.21693407,-0.23743446,0.008339607,0.20807722,-0.38685092,-0.13578607
    , -0.08304207,-0.31454262,0.24718626,0.25853795,-0.062881574,-0.061706975,0.02155601,-0.1778775,-0.15828326,-0.2116507
    , -0.18039164,-0.12908219,0.19001491,0.100622065,-0.1191522,0.077499084,0.045061354,-0.05766226,0.13597104,-0.021555837
    , -0.017214248,0.31838036,-0.024833336,0.20933808,0.13540085,0.05600579,-0.051495276,-0.31906128,-0.0046074544,0.095641844
    , -0.25086924,-0.25445542,0.013246302,-0.16928405,0.25480098,-0.22013791,0.2638766,-0.3059975,0.18744013,-0.023321962
    , -0.37649214,-0.20340835,0.13742602,-0.35521594,0.2863054,0.009014298,0.2603466,-0.0865122,0.08559428,-0.19084495
    , 0.21148506,-0.0842237,0.22159693,-0.21260598,-0.24212119,-0.093673624,0.1660066,-0.31294468,-0.056335416,-0.18678866
    , -0.06403472,-0.032869782,0.13967197,-0.053275853,-0.14575937,-0.033488035,-0.15003932,0.20987748,-0.10270873,0.073441006
    , -0.38443753,0.070068546,-0.39194626,0.15382202,-0.011451212,-0.20068906,-0.28619173,-0.4041582,-0.3918984,-0.18151037
    , 0.24747902,-0.24319942,-0.2303698,0.036614854,0.07469515,0.046845213,-0.109344125,-0.2552228,0.25925744,0.22165495
    , -0.0026765475,0.23769338,0.026978174,0.0050630267,-0.15777235,0.18670604,-0.07262313,0.057549603,-0.2883511,0.30375615
    , 0.12971653,-0.28584325,0.23499641,-0.32125735,-0.024547754,0.06843218,-0.15966299,-0.031510774,0.11001005,0.10651346
    , -0.00063525443,-0.15156777,-0.40162256,-0.1568588,-0.22454762,-0.25875804,0.15417695,0.009069362,-0.04035638,-0.11569427
    , -0.28179264,-0.37882748,-0.21081853,0.28833148,-0.16572686,-0.09465656,-0.19670214,-0.118755154,0.015404563,0.26460266
    , -0.2811112,-0.042845286,-0.032650888,0.15798208,-0.27467012,0.05217488,-0.39034274,0.086978585,-0.13705474,-0.20925581
    , -0.35271057,0.18605289,-0.42342845,-0.14181912,-0.099777795,-0.13905305,-0.28969768,-0.09355453,0.1126502,0.24647696
    , -0.1865473,0.18994612,-0.33747512,-0.17375447,0.08097989,0.11598768,0.16167527,0.24912071,0.23924966,0.133494
    , 0.14792973,-0.34556183,-0.17498903,0.06296327,-0.021778183,0.11759793,-0.09963954,0.13483295,0.15763785,0.25094157
    , -0.23378977,0.14229815,0.23369066,-0.030761361,0.08263524,-0.33740255,-0.24707721,-0.096685305,0.15516149,0.22076145
    , 0.0076515027,0.033048157,0.27338088,0.057352472,0.002552937,0.155074,0.08129357,-0.25381327,0.15532783,-0.17020552
    , -0.33898035,0.08646427,-0.073990144,0.12909965,-0.24436437,0.13620408,-0.2714688,-0.37550852,0.2773086,0.26698205
    , -0.12457423,-0.38689873,0.2675809,-0.03973509,0.14517234,0.16282721,-0.15360583,-0.14212862,-0.08080556,0.030916838
    , -0.10316778,-0.27707422,0.04852912,-0.3045832,-0.19075282,-0.0154925315,-0.21279566,-0.1738775,-0.35818005,-0.29264626
    , 0.03645981,-0.21399406,-0.3587009,-0.14580134,-0.24854055,-0.0029659015,0.20245515,0.1695536,-0.08210852,0.20220001
    , 0.14325222,-0.23039664,-0.083074644,-0.0828605,-0.36995265,0.2588389,-0.20143121,0.16528027,-0.16225286,-0.20665164
    , 0.22586346,0.1596709,-0.007469867,0.13325725,0.09487331,-0.19347118,0.08810943,-0.4285142,-0.28495058,0.008678941
    , 0.051172312,0.101506725,0.1287167,-0.17017722,0.15087608,-0.022972856,-0.16315953,0.11091631,-0.09683362,0.20299874
    , -0.3765157,-0.11166791,-0.157965,0.09239075,0.12178408,0.15738878,-0.26810628,0.08061361,-0.16892152,0.06770679
    , -0.295056,0.08970332,-0.30688718,0.18880925,0.18342827,0.27486655,-0.27216107,-0.0030925183,-0.13486348,0.048378173
    , -0.056968536,-0.35293657,-0.07301995,0.14439164,0.05431987,0.2680426,-0.2759858,-0.1008645,0.005859066,0.16537413
    , 0.15015641,0.08147281,-0.2634447,-0.23523405,-0.43840486,-0.16053455,-0.19518246,0.007089169,-0.23376682,-0.27591103
    , 0.17863667,0.12486695,0.06259054,-0.062049147,-0.026537422,0.23268525,0.18118693,-0.36797458,-0.17580222,-0.0041976296
    , 0.14963345,-0.25017437,-0.27515453,-0.0036992903,0.13815457,-0.21154389,0.037923798,-0.2926163,-0.43895587,0.05488443
    , 0.028651047,-0.16932873,0.19514386,0.09769582,-0.08597395,0.074366964,-0.18527642,0.34603128,0.02300123,-0.2579427
    , 0.1564259,0.17725055,0.15202856,-0.07620826,0.21611865,-0.3568225,0.24740392,0.12550396,-0.28287312,0.09540087
    , -0.12330262,0.09804614,-0.10878352,-0.3001876,0.40270606,-0.08234216,-0.19460805,-0.15048793,-0.65902126,-0.0307954
    , -0.23991787,-0.26032642,-0.105776824,0.10357793,0.1084481,0.12493308,-0.2652144,0.13337147,-0.14797892,-0.20344673
    , -0.24462156,0.065141834,-0.07538944,-0.26555368,0.054926418,0.09371051,-0.35046402,-0.20557871,0.2313459,-0.0741669
    , -0.033237845,-0.07063437,0.3189311,0.030729113,-0.40629798,0.080578,0.237583,-0.0741762,0.16447212,-0.17126541
    , -0.2410422,0.264525,0.1587867,0.10139042,-0.18958344,0.25764444,-0.11972849,0.061067663,0.036045298,-0.24048847
    , 0.061487928,-0.0020102859,-0.0862293,-0.11825358,0.18792583,-0.07744836,-0.1684408,0.28903186,-0.28737944,-0.14890356
    , 0.17182696,0.13372582,-0.22569154,-0.31182554,-0.11538462,0.08410201,0.17940032,0.004206428,0.20186874,-0.35914078
    , 0.16207726,-0.16569817,-0.36157167,-0.26447695,0.26764718,-0.09216393,-0.12980008,-0.31220472,-0.073606975,0.028876372
    , 0.15526807,0.18456025,-0.3484531,-0.23321117,-0.32765284,0.16139576,0.13492283,0.13838425,0.14015588,0.2070449
    , 0.29296368,-0.29161677,-0.103819355,0.14079483,-0.19583632,0.15502149,0.14135127,-0.14243919,0.21612027,0.22113982
    , 0.1728785,-0.4815412,0.22108261,0.31291538,0.15021065,-0.36391872,-0.018980153,-0.11397258,-0.22103828,-0.14868061
    , 0.010572039,-0.3461682,0.08293914,-0.02238321,0.1665259,-0.10736814,-0.30100998,-0.08785928,-0.024067875,-0.1373981
    , -0.27080223,0.23404627,-0.11862265,-0.026266696,0.22511005,-0.3782455,-0.13704494,0.1574083,-0.35495833,0.21086757
};

#endif /* __LENET_5_D7_PARAMS_H__ */
