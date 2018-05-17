// Copyright 2018 Esri.

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "MapImageProvider.h"

#include <QQuickImageProvider>

MapImageProvider::MapImageProvider() :
  QQuickImageProvider(QQuickImageProvider::Image)
{
}

// reimplemented function for QML to request Images from the provider
QImage MapImageProvider::requestImage(const QString& id, QSize* size, const QSize &requestedSize)
{  
  Q_UNUSED(size)
  Q_UNUSED(requestedSize)
  return m_images[id];
}

// helper to add images to the the provider
void MapImageProvider::addImage(const QString& id, const QImage& img)
{
  m_images[id] = img;
}

// static function to return the image provider id
QString MapImageProvider::imageProviderId()
{
  return QStringLiteral("mapimageprovider");
}
