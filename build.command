#!/usr/bin/env bash

cd "$(dirname "$0")"

xcodebuild archive \
-scheme CppSimde \
-destination "generic/platform=iOS" \
-archivePath ./Build/CppSimde-iOS \
SKIP_INSTALL=NO \
BUILD_LIBRARY_FOR_DISTRIBUTION=YES

xcodebuild archive \
-scheme CppSimde \
-destination "generic/platform=iOS Simulator" \
-archivePath ./Build/CppSimde-Sim \
SKIP_INSTALL=NO \
BUILD_LIBRARY_FOR_DISTRIBUTION=YES

xcodebuild archive \
-scheme CppSimde \
-destination "generic/platform=OS X" \
-archivePath ./Build/CppSimde-OSX \
SKIP_INSTALL=NO \
BUILD_LIBRARY_FOR_DISTRIBUTION=YES

cd ./Build

xcodebuild -create-xcframework \
-framework ./CppSimde-iOS.xcarchive/Products/Library/Frameworks/CppSimde.framework \
-framework ./CppSimde-Sim.xcarchive/Products/Library/Frameworks/CppSimde.framework \
-framework ./CppSimde-OSX.xcarchive/Products/Library/Frameworks/CppSimde.framework \
-output ./CppSimde.xcframework