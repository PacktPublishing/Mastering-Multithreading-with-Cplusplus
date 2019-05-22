QThreadStorage<QCache<QString, SomeClass> > caches;

void cacheObject(const QString &key, SomeClass* object) {
 caches.localData().insert(key, object);
}

void removeFromCache(const QString &key) {
 if (!caches.hasLocalData()) { return; }
 
 caches.localData().remove(key);
}
