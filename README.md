# CNanoMessage

[![Swift][swift-badge-3]][swift-url]
[![Swift][swift-badge-4]][swift-url]
[![License][mit-badge]][mit-url]

Modulemap for [nanomsg](http://nanomsg.org/).

Consumed by [NanoMessage](https://github.com/itssofluffy/NanoMessage).

## Usage

If [Swift Package Manager](https://github.com/apple/swift-package-manager) is used, add this package as a dependency in `Package.swift`,

```swift
import PackageDescription

let package = Package (
    name:  "<your-app-name>",
    dependencies: [
        .Package(url: "https://github.com/itssofluffy/CNanoMessage.git", majorVersion: 0)
    ]
)
```

## License

This project is released under the MIT license. See [LICENSE](LICENSE) for details.

[swift-badge-3]: https://img.shields.io/badge/Swift-3.0-orange.svg?style=flat
[swift-badge-4]: https://img.shields.io/badge/Swift-4.0-orange.svg?style=flat
[swift-url]: https://swift.org
[mit-badge]: https://img.shields.io/badge/License-MIT-blue.svg?style=flat
[mit-url]: https://tldrlegal.com/license/mit-license
