:Pod::Spec.new do |s|
    s.name            = "QRMasterBTSDK"
    s.version         = "1.0.0"
    s.ios.deployment_target = '7.0'
    s.summary         = "这个畅联科技锁掌柜的蓝牙接口"
    s.homepage        = "https://github.com/StarsRain"
    s.license         ={ :type => "MIT", :file => "LICENSE"}
    s.author          = { "Simple" => "308140283@qq.com"}
    s.source          = { :git => "https://github.com/StarsRain/QRMasterBTSDK.git", :tag => s.version}
    s.resource        = "QRMasterBTSDK/BlueSDK.bundle"
    s.frameworks      = 'Foundation','UIKit'
    s.requires_arc    = true
