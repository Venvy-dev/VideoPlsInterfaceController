#
# Be sure to run `pod lib lint VideoPlsInterfaceViewSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'VideoPlsInterfaceController'
  s.version          = '2.0.9'
  s.summary          = 'VideoPls Public Interface Controller.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
                      'VideoPls Interface Controller for easy using VideoOS and LiveOS.'
                       DESC

  s.homepage         = 'https://github.com/Zard1096/VideoPlsInterfaceController.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Zard1096'     => 'mr.zardqi@gmail.com',
                         'LiShaoshuai'  => 'lishaoshuai1990@gmail.com',   
                         'Bill'         => 'fuleiac@gmail.com'          }
  s.source           = { :http => 'http://global-sdk.oss-cn-beijing.aliyuncs.com/iOS_package/VideoPlsInterfaceControllerSDK/VideoPlsInterfaceControllerSDK-2.0.9.zip' }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.libraries = 'z', 'sqlite3'
  s.frameworks = 'AVFoundation', 'CoreTelephony', 'SystemConfiguration', 'ImageIO', 'MobileCoreServices', "WebKit", 'CoreMedia', 'Accelerate'
  s.dependency 'AFNetworking', '~>3.0'

  s.vendored_frameworks = 'VideoPlsInterfaceControllerSDK.framework'

  s.xcconfig = { 
      'GCC_PREPROCESSOR_DEFINITIONS' => '$(inherited) VP_LIVEOS=1'
    }
  # s.resource_bundles = {
  #   'VideoPlsInterfaceViewSDK' => ['VideoPlsInterfaceViewSDK/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
